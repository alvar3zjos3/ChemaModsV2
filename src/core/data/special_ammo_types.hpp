#pragma once
#include "weapon/CAmmoInfo.hpp"

struct SpecialAmmo
{
	char name[32];
	eAmmoSpecialType type;
};

constexpr std::array<SpecialAmmo, 7> SPECIAL_AMMOS = {{
    {"Sin Munición Especial", eAmmoSpecialType::None},
    {"Munición Perforante", eAmmoSpecialType::ArmorPiercing},
    {"Munición Explosiva", eAmmoSpecialType::Explosive},
    {"Munición Full Metal Jacket", eAmmoSpecialType::FMJ},
    {"Munición Punta Hueca", eAmmoSpecialType::HollowPoint},
    {"Munición Incendiaria", eAmmoSpecialType::Incendiary},
    {"Munición Trazadora", eAmmoSpecialType::Tracer},
}};