#include "backend/player_command.hpp"
#include "core/scr_globals.hpp"
#include "util/scripts.hpp"

namespace big
{
	class end_session_kick : player_command
	{
		using player_command::player_command;

		virtual CommandAccessLevel get_access_level() override
		{
			return CommandAccessLevel::TOXIC;
		}

		virtual void execute(player_ptr player, const command_arguments& _args, const std::shared_ptr<command_context> ctx) override
		{
			if (!player || !player->is_valid())
				return;
			if (!scripts::force_host("freemode"_J))
			{
				g_notification_service.push_error("EXPULSION_END_SESSION", "No se pudo forzar el host del script.");
				return;
			}

			player->trigger_end_session_kick = true;
			*scr_globals::gsbd.as<int*>() = (int)(__rdtsc() % 50000) + 6;
			script::get_current()->yield(5s);
			*scr_globals::gsbd.as<int*>() = 4;
		}
	};

	end_session_kick g_end_session_kick("endkick", "EXPULSION_FINAL_SESION", "EXPULSION_FINAL_SESION_DESC", 0);
}
