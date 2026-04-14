#include "backend/player_command.hpp"
#include "util/scripts.hpp"

namespace big
{
	template<rage::joaat_t script_hash>
	class start_script : player_command
	{
		using player_command::player_command;

		virtual CommandAccessLevel get_access_level() override
		{
			return CommandAccessLevel::AGGRESSIVE;
		}

		virtual void execute(player_ptr player, const command_arguments& _args, const std::shared_ptr<command_context> ctx) override
		{
			scripts::force_script_on_player(player, script_hash);
		}
	};

	start_script<"fm_intro"_J> g_start_tutorial("tutorial", "INICIAR_TUTORIAL", "INICIAR_TUTORIAL_DESC", 0);
	start_script<"golf_mp"_J> g_start_golf("golf", "INICIAR_GOLF", "INICIAR_GOLF_DESC", 0);
	start_script<"Pilot_School_MP"_J> g_start_flight_school("flightschool", "INICIAR_ESCUELA_DE_VUELO", "INICIAR_ESCUELA_DE_VUELO_DESC", 0);
	start_script<"AM_Darts"_J> g_start_darts("darts", "INICIAR_DARDOS", "INICIAR_DARDOS_DESC", 0);
	start_script<"gunslinger_arcade"_J> g_start_badlands("badlands", "INICIAR_BADLANDS_REVENGE_II", "INICIAR_BADLANDS_REVENGE_II_DESC", 0);
	start_script<"ggsm_arcade"_J> g_start_space_monkey("spacemonkey", "INICIAR_SPACE_MONKEY", "INICIAR_SPACE_MONKEY_DESC", 0);
	start_script<"wizard_arcade"_J> g_start_wizards_ruin("wizard", "INICIAR_WIZARD", "INICIAR_WIZARD_DESC", 0);
	start_script<"puzzle"_J> g_start_qub3d("qub3d", "INICIAR_QUB3D", "INICIAR_QUB3D_DESC", 0);
	start_script<"camhedz_arcade"_J> g_start_camhedz("camhedz", "INICIAR_CAMHEDZ", "INICIAR_CAMHEDZ_DESC", 0);
}