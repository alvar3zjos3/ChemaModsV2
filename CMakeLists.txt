cmake_minimum_required(VERSION 3.20)

set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

project(ChemaModsV2 CXX ASM_MASM)

if (NOT MSVC)
  message(FATAL_ERROR "Unsupported compiler used '${CMAKE_CXX_COMPILER_ID}', ChemaModsV2 only supports MSVC.")
endif()

set(SRC_DIR "${PROJECT_SOURCE_DIR}/src")

# Git commit embed
include(cmake/git.cmake)

# Fetch modules
message("\nFetching modules")
include(cmake/asmjit.cmake)
include(cmake/minhook.cmake)
include(cmake/async-logger.cmake)
include(cmake/pugixml.cmake)
include(cmake/json.cmake)
include(cmake/cpr.cmake)
include(cmake/lua.cmake)
include(cmake/imgui.cmake)
message("\nFetching custom modules")
include(cmake/gtav-classes.cmake)


# ChemaModsV2
message(STATUS "ChemaModsV2")
file(GLOB_RECURSE SRC_MAIN
    "${SRC_DIR}/**.hpp"
    "${SRC_DIR}/**.h"
    "${SRC_DIR}/**.cpp"
    "${SRC_DIR}/**.cc"
    "${SRC_DIR}/**.cxx"
    "${SRC_DIR}/**.asm"
)

if (MSVC)
  add_compile_options(/bigobj)
  add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
  add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")
else ()
  add_compile_options(-Wa,-mbig-obj)
endif ()

add_library(ChemaModsV2 MODULE "${SRC_MAIN}" "src/services/script_function_hook/script_function_hook_service.cpp")

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(TARGET ChemaModsV2 PROPERTY CXX_STANDARD 23) # 23 Because std::format is not avalible in std:c++20 for some reason. Maybe it's because i use v142 toolset.

source_group(TREE ${SRC_DIR} PREFIX "src" FILES ${SRC_MAIN} )

target_include_directories(ChemaModsV2 PRIVATE 
    "${SRC_DIR}"
    "${json_SOURCE_DIR}/single_include"
    "${gtav_classes_SOURCE_DIR}"
    "${imgui_SOURCE_DIR}"
    "${minhook_SOURCE_DIR}/src/hde"
    "${asmjit_SOURCE_DIR}/src"
)

target_precompile_headers(ChemaModsV2 PRIVATE "${SRC_DIR}/common.hpp")
target_link_libraries(ChemaModsV2 PRIVATE pugixml minhook AsyncLogger dbghelp imgui cpr lua_static asmjit::asmjit)

# Warnings as errors
set_property(TARGET ChemaModsV2 PROPERTY COMPILE_WARNING_AS_ERROR ON)

add_compile_definitions(ChemaModsV2 
    "_CRT_SECURE_NO_WARNINGS"
    "NOMINMAX"
    "WIN32_LEAN_AND_MEAN"
)

# Optimizations
if(MSVC)
    if(OPTIMIZE)
      set(CMAKE_MODULE_LINKER_FLAGS
          "${CMAKE_MODULE_LINKER_FLAGS} /LTCG /OPT:REF,ICF /GUARD:NO")

      set(CMAKE_CXX_FLAGS_RELWITHDEBINFO
          "${CMAKE_CXX_FLAGS_RELWITHDEBINFO} /O2 /Oi /Ot /Oy /Ob3 /sdl- /GL /GF /GS- /Gw")
      string(REPLACE "/Ob1" "/Ob3" CMAKE_CXX_FLAGS_RELWITHDEBINFO ${CMAKE_CXX_FLAGS_RELWITHDEBINFO})
    else()
        add_compile_definitions(YIM_DEV)
    endif()
endif()
