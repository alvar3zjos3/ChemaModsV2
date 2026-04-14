#include "backend/looped_command.hpp"
#include "natives.hpp"

namespace big
{
	class siren_mute : looped_command
	{
		using looped_command::looped_command;

		virtual void on_tick() override
		{
			if (ENTITY::DOES_ENTITY_EXIST(self::veh))
			{
				VEHICLE::SET_VEHICLE_HAS_MUTED_SIRENS(self::veh, true);
			}
		}

		virtual void on_disable() override
		{
			if (ENTITY::DOES_ENTITY_EXIST(self::veh))
			{
				VEHICLE::SET_VEHICLE_HAS_MUTED_SIRENS(self::veh, false);
			}
		}
	};

	siren_mute g_siren_mute("mutesiren", "SILENCIAR_SIRENA", "MUTE_SIREN_DESC", g.vehicle.siren_mute);
}
