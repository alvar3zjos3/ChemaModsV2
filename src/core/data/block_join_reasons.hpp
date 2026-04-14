#pragma once

namespace big
{
	enum block_join_reason_t : int32_t
	{
		UNK_0 = 0,

		None = 1,

		UNK_2 = 2,
		UNK_3 = 3,
		UNK_4 = 4,

		// Ya te han votado para salir de esta sesión de juego.
		BeenVotedOut = 5,

		UNK_6 = 6,

		// Error al unirte a la sesión debido a archivos incompatibles.
		IncompatibleAssets = 7,

		// La sesión a la que intentas unirte está llena.
		SessionFull = 8,

		// La sesión a la que intentas unirte está llena de jugadores.
		SlotFull = 9,

		// Asegúrate de que todos los jugadores tengan la última actualización del título.
		NoTitleUpdate = 10,

		UNK_11 = 11,

		// Las invitaciones están desactivadas en esta sesión.
		InvitesDisabled = 12,

		// La sesión a la que intentas unirte usa una preferencia de apuntado diferente.
		DifferentTargetingMode = 13,

		// Estás clasificado como tramposo y solo puedes jugar con otros tramposos hasta que seas perdonado.
		Cheater = 14,

		UNK_15 = 15,

		// Contenido descargable incompatible. Todos los jugadores deben tener el último paquete de compatibilidad.
		IncompatibleDLC = 16,

		// Intentas entrar a una sesión solo para miembros de crew.
		CrewOnly = 17,

		// La sesión a la que intentas unirte es para jugadores que no son malos deportistas ni tramposos - tú eres un mal deportista.
		BadSport = 18,

		// La sesión a la que intentas unirte es solo para malos deportistas.
		BadSportOnly = 19,

		// La sesión a la que intentas unirte es solo para tramposos.
		CheatersOnly = 20,

		// La sesión a la que intentas unirte ya no existe.
		SessionNoLongerExists = 21,

		// La sesión a la que intentas unirte es privada. Necesitas una invitación para unirte.
		InviteOnly = 22,

		// La sesión a la que intentas unirte es privada y solo para amigos. Debes ser invitado por un amigo.
		InviteAndFriendsOnly = 23,

		// La sesión a la que intentas unirte es de un tipo de compilación diferente.
		DifferentBuildType = 24,

		UNK_25 = 25,

		// La sesión a la que intentas unirte no usa el mismo contenido.
		DifferentContent = 26,

		// La sesión a la que intentas unirte es solo para amigos.
		FriendsOnly = 27,

		// No se puede unir. Tu cuenta tiene mala reputación.
		BadReputation = 28,

		// No se puede conectar a la sesión. Es posible que la sesión ya no exista.
		MayNotExist = 29,

		// No se puede unir. La sesión a la que intentas unirte es una Carrera Premium. Unirse y aceptar invitaciones está desactivado para este modo.
		PremiumRace = 30
	};

	inline block_join_reason_t& operator++(block_join_reason_t& reason)
	{
		reason = static_cast<block_join_reason_t>(static_cast<int32_t>(reason) + 1);

		return reason;
	}

	inline block_join_reason_t operator++(block_join_reason_t& reason, int32_t)
	{
		block_join_reason_t a = reason;
		++reason;
		return a;
	}

	inline constexpr auto block_join_reasons = std::to_array({
	    "",                              // 0
	    "Ninguno",                       // 1
	    "",                              // 2
	    "",                              // 3
	    "",                              // 4
	    "Votado para salir",             // 5
	    "",                              // 6
	    "Archivos incompatibles",        // 7
	    "Sesión llena",                  // 8
	    "Slots llenos",                  // 9
	    "Sin actualización",             // 10
	    "",                              // 11
	    "Invitaciones desactivadas",     // 12
	    "Modo de apuntado diferente",    // 13
	    "Tramposo",                      // 14
	    "",                              // 15
	    "DLC incompatible",              // 16
	    "Solo crew",                     // 17
	    "Mal deportista",                // 18
	    "Solo malos deportistas",        // 19
	    "Solo tramposos",                // 20
	    "Sesión ya no existe",           // 21
	    "Solo con invitación",           // 22
	    "Solo amigos e invitación",      // 23
	    "Tipo de compilación diferente", // 24
	    "",                              // 25
	    "Contenido diferente",           // 26
	    "Solo amigos",                   // 27
	    "Mala reputación",               // 28
	    "Puede que no exista",           // 29
	    "Carrera Premium"                // 30
	});
}