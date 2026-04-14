#include "backend/command.hpp"

namespace big
{
	class recovery : command
	{
		using command::command;

		virtual CommandAccessLevel get_access_level() override
		{
			return CommandAccessLevel::NONE;
		}

		virtual void execute(const command_arguments&, const std::shared_ptr<command_context> ctx) override
		{
            ctx->report_error("Las opciones de dinero y recuperación no son compatibles con ChemaModsV2 para mantener contentas a Rockstar/Take Two. Puedes probar Kiddion's Modest Menu (gratis), pero asegúrate de descargarlo solo desde UnknownCheats.me; el resto son estafas y pueden contener malware");
		}
	};

	recovery g_money("money", "", "", 0);
	recovery g_cash("cash", "", "", 0);
	recovery g_drop("drop", "", "", 0);
	recovery g_stats("stats", "", "", 0);
}