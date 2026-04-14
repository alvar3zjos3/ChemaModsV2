#include "backend/looped_command.hpp"
#include "natives.hpp"
#include "script.hpp"
#include "util/blip.hpp"

namespace big
{
	class waypoint_beacon : looped_command
	{
		using looped_command::looped_command;

		virtual void on_tick() override
		{
			Vector3 location;

			if (blip::get_blip_location(location, (int)BlipIcons::RADAR_WAYPOINT))
			{
				int color[3] = {0, 0, 0};

				for (int i = 0; i < 3; i++)
					color[i] = (int)(255 * g.world.waypoint_n_objective.waypoint_beacon_color[i]);

				MISC::GET_GROUND_Z_FOR_3D_COORD(location.x, location.y, location.z, &location.z, 1, 0);

				GRAPHICS::DRAW_MARKER_EX(1,
				    location.x,
				    location.y,
				    location.z,
				    0.f,
				    0.f,
				    0.f,
				    0.f,
				    0.f,
				    0.f,
				    7.5f,
				    7.f,
				    location.z + 1500.f,
				    color[0],
				    color[1],
				    color[2],
				    180,
				    0,
				    0,
				    2,
				    0,
				    0,
				    0,
				    0,
				    1,
				    1);
			}
		}
	};

	class objective_beacon : looped_command
	{
		using looped_command::looped_command;

		virtual void on_tick() override
		{
			Vector3 location;

			if (blip::get_objective_location(location))
			{
				int color[3] = {0, 0, 0};

				for (int i = 0; i < 3; i++)
					color[i] = (int)(255 * g.world.waypoint_n_objective.objective_beacon_color[i]);

				MISC::GET_GROUND_Z_FOR_3D_COORD(location.x, location.y, location.z, &location.z, 1, 0);

				GRAPHICS::DRAW_MARKER_EX(1,
				    location.x,
				    location.y,
				    location.z,
				    0.f,
				    0.f,
				    0.f,
				    0.f,
				    0.f,
				    0.f,
				    7.5f,
				    7.f,
				    location.z + 1500.f,
				    color[0],
				    color[1],
				    color[2],
				    180,
				    0,
				    0,
				    2,
				    0,
				    0,
				    0,
				    0,
				    1,
				    1);
			}
		}
	};

	waypoint_beacon g_waypoint_beacon("balizawp", "BALIZA_DE_MARCADOR", "BACKEND_LOOPED_WORLD_BEACON_WAYPOINT_DESC", g.world.waypoint_n_objective.waypoint_beacon);
	objective_beacon g_objective_beacon("balizaobjetivo", "BALIZA_DE_OBJETIVO", "BACKEND_LOOPED_WORLD_BEACON_OBJECTIVE_DESC", g.world.waypoint_n_objective.objective_beacon);
}