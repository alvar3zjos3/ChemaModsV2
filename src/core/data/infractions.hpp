#pragma once

namespace big
{
	// Lua API: Infracción
	enum class Infraction
	{
		// Añade nuevos valores al final (para serialización)

		DESYNC_PROTECTION,
		BREAKUP_KICK_DETECTED,         // no usar
		LOST_CONNECTION_KICK_DETECTED, // no usar
		SPOOFED_ROCKSTAR_ID,           // no usar
		TRIGGERED_ANTICHEAT,
		TRIED_CRASH_PLAYER,
		TRIED_KICK_PLAYER,
		BLAME_EXPLOSION_DETECTED, // no usar (por ahora)
		ATTACKING_WITH_GODMODE,
		ATTACKING_WITH_INVISIBILITY,
		ATTACKING_WHEN_HIDDEN_FROM_PLAYER_LIST,
		SPOOFED_DATA,
		SPOOFED_HOST_TOKEN,
		INVALID_PLAYER_MODEL,
		SUPER_JUMP,
		UNDEAD_OTR,
		// Para que los scripts de lua puedan añadir una razón personalizada en tiempo de ejecución.
		CUSTOM_REASON,
		CHAT_SPAM,
		SENT_MODDER_BEACONS
	};
}