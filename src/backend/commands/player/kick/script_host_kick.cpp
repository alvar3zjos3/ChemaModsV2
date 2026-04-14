#include "backend/player_command.hpp"
#include "core/scr_globals.hpp"
#include "util/scripts.hpp"

namespace big
{
	class script_host_kick : player_command
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
				g_notification_service.push_error("Expulsión", "No se pudo forzar el host del script.");
				return;
			}

			*scr_globals::gsbd_kicking.at(player->id(), 1).as<bool*>() = true;
		}
	};

	script_host_kick g_script_host_kick("shkick", "EXPULSION_SCRIPT_HOST", "EXPULSION_SCRIPT_HOST_DESC", 0, false);
}
