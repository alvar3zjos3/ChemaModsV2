#pragma once
#include "core/enums.hpp"

namespace big
{
	inline std::unordered_map<CommandAccessLevel, const char*> COMMAND_ACCESS_LEVELS = {
	    {CommandAccessLevel::NONE, "Ninguno"},
	    {CommandAccessLevel::FRIENDLY, "Amistoso"},
	    {CommandAccessLevel::AGGRESSIVE, "Agresivo"},
	    {CommandAccessLevel::TOXIC, "Tóxico"},
	    {CommandAccessLevel::ADMIN, "Admin (!)"},
	};
}