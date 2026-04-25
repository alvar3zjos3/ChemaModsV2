#include "script_handler.hpp"

#include "pointers.hpp"

#include <network/CNetworkPlayerMgr.hpp>

int CGameScriptHandlerNetComponent::get_participant_index(CNetGamePlayer* player)
{
	for (auto* p = m_first_participant; p; p = p->m_next)
		if (p->m_net_game_player == player)
			return p->m_participant_index;

	return -1;
}

bool CGameScriptHandlerNetComponent::is_player_a_participant(CNetGamePlayer* player)
{
	for (auto* p = m_first_participant; p; p = p->m_next)
		if (p->m_net_game_player == player)
			return true;

	return false;
}