#pragma once
#include "common.hpp"
#include "services/players/player_service.hpp"

namespace big
{
	struct spawned_ped
	{
		Ped ped_handle;
		Player spawned_for_player;
		bool is_bodyguard;
		bool is_attacker;
	};

	inline std::vector<spawned_ped> spawned_peds;

	class looped
	{
	public:
		static void hud_transition_state();
		static void hud_disable_input();

		static void player_good_options();           // Opciones buenas para jugadores
		static void player_toxic_options();          // Opciones tóxicas para jugadores
		static void player_spectate();               // Espectar jugador
		static void player_remote_control_vehicle(); // Control remoto de vehículo del jugador

		static void self_wanted();                   // Nivel de búsqueda propio
		static void self_hud();                      // HUD propio
		static void self_persist_outfit();           // Guardar atuendo de forma permanente

		static void session_pop_multiplier_areas();  // Multiplicador de población en la sesión
		static void session_force_thunder();         // Forzar truenos
		static void session_block_jobs();            // Bloquear trabajos
		static void session_randomize_ceo_colors();  // Colores aleatorios de CEO
		static void session_auto_kick_host();        // Auto expulsar al host
		static void session_force_script_host();     // Forzar ser host del script
		static void session_chat_translator();       // Traductor del chat
		static void session_modder_detection();      // Detección de modders

		static void system_self_globals();           // Globals propios del sistema
		static void system_update_pointers();        // Actualizar punteros
		static void system_update_desync_kick();     // Actualizar kick por desincronización
		static void system_spoofing();               // Spoofing del sistema
		static void system_mission_creator();        // Creador de misiones

		static void vehicle_auto_drive();            // Conducción automática
		static void vehicle_allow_all_weapons();     // Permitir todas las armas en vehículos
		static void vehicle_boost_behavior();        // Comportamiento del boost
		static void vehicle_rainbow_paint();         // Pintura arcoíris

		static void weapons_tp_gun();                // Arma de teletransporte
		static void weapons_ammo_special_type();     // Tipo de munición especial
		static void weapons_cage_gun();              // Arma de jaula
		static void custom_gun_disable_control_action(); // Desactivar controles de armas personalizadas
		static void weapons_delete_gun();            // Arma de eliminación
		static void weapons_gravity_gun();           // Arma de gravedad
		static void weapons_repair_gun();            // Arma de reparación
		static void weapons_steal_vehicle_gun();     // Arma de robar vehículo
		static void weapons_vehicle_gun();           // Arma de spawn de vehículos
		static void weapons_c4_limit();              // Límite de C4
		static void weapons_do_persist_weapons();    // Armas persistentes
		static void weapons_do_weapon_hotkeys();     // Atajos de armas
		static void weapons_paint_gun();             // Arma de pintura

		static void drive_train();                   // Conducir tren
		static void derail_train();                  // Descarrilar tren

		static void world_spawn_ped();               // Spawn de peds en el mundo
	};
}
