#include "backend/bool_command.hpp"
#include "backend/int_command.hpp"
#include "backend/looped/looped.hpp"
#include "natives.hpp"
#include "script.hpp"

namespace big
{
	float red = 255.f, green = 0.f, blue = 0.f;
	void looped::vehicle_rainbow_paint()
	{
		static std::chrono::system_clock::time_point last_rgb_run_time;
		static std::chrono::milliseconds delay = 0s;
		static bool ran                        = false;

		if (self::veh && g.vehicle.rainbow_paint.type != RainbowPaintType::Off)
		{
			if (g.vehicle.rainbow_paint.type == RainbowPaintType::Spasm && last_rgb_run_time + delay < std::chrono::system_clock::now())
			{
				red   = rand() % 255;
				green = rand() % 255;
				blue  = rand() % 255;
				delay             = std::chrono::milliseconds((110) - (g.vehicle.rainbow_paint.speed * 10));
				last_rgb_run_time = std::chrono::system_clock::now();
				ran               = true;
			}

			if (g.vehicle.rainbow_paint.type == RainbowPaintType::Fade)
			{
				if (ran) { red = 255; green = 0; blue  = 0; ran   = false; }

				if (red > 0 && blue == 0)
				{
					green += g.vehicle.rainbow_paint.speed;
					red -= g.vehicle.rainbow_paint.speed;
				}
				if (green > 0 && red == 0)
				{
					blue += g.vehicle.rainbow_paint.speed;
					green -= g.vehicle.rainbow_paint.speed;
				}
				if (blue > 0 && green == 0)
				{
					red += g.vehicle.rainbow_paint.speed;
					blue -= g.vehicle.rainbow_paint.speed;
				}
				red   = std::clamp(red, 0.f, 255.f);
				green = std::clamp(green, 0.f, 255.f);
				blue  = std::clamp(blue, 0.f, 255.f);
			}

			if (g.vehicle.rainbow_paint.primary)
			{
				VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(self::veh, red, green, blue);
			}
			if (g.vehicle.rainbow_paint.secondary)
			{
				VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(self::veh, red, green, blue);
			}
			if (g.vehicle.rainbow_paint.neon)
			{
				VEHICLE::SET_VEHICLE_NEON_COLOUR(self::veh, red, green, blue);
			}
			if (g.vehicle.rainbow_paint.smoke)
			{
				VEHICLE::SET_VEHICLE_TYRE_SMOKE_COLOR(self::veh, red, green, blue);
			}
		}
	}

	bool_command g_rainbow_paint_primary("rainbowpri", "PINTURA_RAINBOW_PRIMARIA", "BACKEND_LOOPED_VEHICLE_RGB_PAINT_PRIMARY_DESC", g.vehicle.rainbow_paint.primary);
	bool_command g_rainbow_paint_secondary("rainbowsec", "PINTURA_RAINBOW_SECUNDARIA", "BACKEND_LOOPED_VEHICLE_RGB_PAINT_SECONDARY_DESC", g.vehicle.rainbow_paint.secondary);
	bool_command g_rainbow_paint_neon("rainbowneons", "NEONES_RAINBOW", "BACKEND_LOOPED_VEHICLE_RGB_PAINT_NEONS_DESC", g.vehicle.rainbow_paint.neon);
	bool_command g_rainbow_paint_smoke("rainbowsmoke", "HUMO_DE_LLANTAS_RAINBOW", "BACKEND_LOOPED_VEHICLE_RGB_PAINT_TIRE_DESC", g.vehicle.rainbow_paint.smoke);
	int_command g_rainbow_paint_speed("rainbowspeed", "VELOCIDAD_RAINBOW", "BACKEND_LOOPED_VEHICLE_RGB_PAINT_SPEED_DESC", g.vehicle.rainbow_paint.speed, 1, 10);
}