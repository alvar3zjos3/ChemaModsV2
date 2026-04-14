#include "backend/looped_command.hpp"
#include "util/misc.hpp"
#include "core/scr_globals.hpp"

namespace big
{
	class fast_respawn : looped_command
	{
		using looped_command::looped_command;

		virtual void on_tick() override
		{
			*scr_globals::disable_wasted_sound.as<bool*>() = true;

			misc::set_bit(&(*scr_globals::freemode_properties.at(1762).at(756).as<int*>()), 1);
		}

		virtual void on_disable() override
		{
			*scr_globals::disable_wasted_sound.as<bool*>() = false;

			misc::clear_bit(&(*scr_globals::freemode_properties.at(1762).at(756).as<int*>()), 1); 
		}
	};

	fast_respawn g_fast_respawn("fastrespawn", "RESPAWN_INSTANTANEO", "INSTANT_RESPAWN_DESC", g.self.fast_respawn);
}
