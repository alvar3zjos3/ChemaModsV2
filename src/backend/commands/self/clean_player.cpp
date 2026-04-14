#include "backend/command.hpp"
#include "natives.hpp"
#include "util/entity.hpp"

namespace big
{
	class clean_player : command
	{
		using command::command;

		virtual void execute(const command_arguments&, const std::shared_ptr<command_context> ctx) override
		{
			entity::clean_ped(self::ped);
		}
	};

	clean_player g_clean_player("clean", "LIMPIAR_JUGADOR", "LIMPIAR_JUGADOR_DESC", 0);
}