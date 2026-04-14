#include "backend/command.hpp"
#include "backend/looped/looped.hpp"
#include "backend/looped_command.hpp"
#include "core/scr_globals.hpp"
#include "util/misc.hpp"
#include "gta_util.hpp"
#include "natives.hpp"

namespace big
{
	bool user_updated_wanted_level = false;

	class clear_wanted : command
	{
		using command::command;

		virtual void execute(const command_arguments&, const std::shared_ptr<command_context> ctx) override
		{
			if (g.self.never_wanted)
				return;

			g_local_player->m_player_info->m_wanted_level = 0;
			g_local_player->m_player_info->m_is_wanted    = false;

			g.self.wanted_level = 0;
		}
	};

	clear_wanted g_clear_wanted("clearwantedself", "LIMPIAR_NIVEL_DE_BUSQUEDA", "CLEAR_WANTED_LEVEL_DESC_SELF", 0);

	class never_wanted : looped_command
	{
		using looped_command::looped_command;

		virtual void on_tick() override
		{
			if (auto script = gta_util::find_script_thread("fm_mission_controller"_J))
			{
				if (!misc::has_bit_set(script_local(script, scr_locals::fm_mission_controller::mission_controller_wanted_state_flags).as<PINT>(), 7))
					return;
			}

			PLAYER::SET_MAX_WANTED_LEVEL(0);
			g_local_player->m_player_info->m_wanted_level = 0;
			g_local_player->m_player_info->m_is_wanted    = false;

			g.self.wanted_level       = 0;
			g.self.force_wanted_level = false;
		}

		virtual void on_disable() override
		{
			PLAYER::SET_MAX_WANTED_LEVEL(5);
		}
	};

	never_wanted g_never_wanted("neverwanted", "NUNCA_BUSCADO", "NEVER_WANTED_DESC", g.self.never_wanted);

	void looped::self_wanted()
	{
		if (g.self.never_wanted)
			return;

		if (g_local_player && g_local_player->m_player_info)
		{
			if (user_updated_wanted_level)
			{
				g_local_player->m_player_info->m_wanted_level = g.self.wanted_level;

				if (g.self.wanted_level == 0)
					g_local_player->m_player_info->m_is_wanted = false;
				else
					g_local_player->m_player_info->m_is_wanted = true;

				user_updated_wanted_level = false;
				return;
			}

			if (g.self.force_wanted_level)
			{
				g_local_player->m_player_info->m_wanted_level = g.self.wanted_level;

				if (g.self.wanted_level == 0)
					g_local_player->m_player_info->m_is_wanted = false;
				else
					g_local_player->m_player_info->m_is_wanted = true;
			}

			if (!user_updated_wanted_level && !g.self.force_wanted_level)
			{
				g.self.wanted_level = g_local_player->m_player_info->m_wanted_level;
			}
		}
	}
}