#pragma once

enum class menu_event
{
	PlayerLeave,               // Jugador salió
	PlayerJoin,                // Jugador entró
	PlayerMgrInit,             // Inicialización del gestor de jugadores
	PlayerMgrShutdown,         // Cierre del gestor de jugadores
	ChatMessageReceived,       // Mensaje de chat recibido
	ScriptedGameEventReceived, // Evento de script recibido
	MenuUnloaded,              // Menú descargado
	ScriptsReloaded,           // Scripts recargados
	Wndproc,                   // Mensaje de ventana
};