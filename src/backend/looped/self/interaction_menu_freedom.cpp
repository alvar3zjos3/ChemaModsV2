#include "backend/looped_command.hpp"
#include "core/scr_globals.hpp"

namespace big
{
	class interaction_menu_freedom : looped_command
	{
		using looped_command::looped_command;

		virtual void on_tick() override
		{
			*scr_globals::interaction_menu_access.as<int*>() = 1;
		}
	};

	interaction_menu_freedom g_interaction_menu_freedom("interactionmenufreedom", "MENU_DE_INTERACCION_LIBRE", "INTERACTION_MENU_FREEDOM_DESC", g.self.interaction_menu_freedom);
}