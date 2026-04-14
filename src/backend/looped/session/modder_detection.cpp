#include "backend/looped/looped.hpp"
#include "gta_util.hpp"
#include "natives.hpp"
#include "pointers.hpp"
#include "util/session.hpp"

namespace big
{
	static bool bLastInSession = false;

	void looped::session_modder_detection()
	{
		if (!bLastInSession && *g_pointers->m_gta.m_is_session_started)
		{
			if (!g_player_service->get_self()->is_host())
			{
				player_ptr host;
				int players{}; // excepto tú
				int opens{};
				std::vector<player_ptr> modded{};

				for (auto& player : g_player_service->players())
				{
					if (player.second->is_valid() && player.second->get_net_data())
					{
						if (player.second->is_host())
							host = player.second;

						if (player.second->get_net_data()->m_nat_type == 0)
							modded.push_back(player.second);
						else if (player.second->get_net_data()->m_nat_type == 1)
							opens++;

						players++;
					}
				}

				if (players > 5 && host && host->get_net_data()->m_nat_type != 0)
				{
					if ((modded.size() / (float)(players - 1)) < 0.5)
					{
						for (auto& player : modded)
							session::add_infraction(player, Infraction::DESYNC_PROTECTION);
					}

					if (opens == (players - 1) && host->get_net_data()->m_nat_type > 1)
					{
						session::add_infraction(host, Infraction::DESYNC_PROTECTION);
					}
				}
			}

			bLastInSession = true;
		}
		else if (bLastInSession && !*g_pointers->m_gta.m_is_session_started)
		{
			bLastInSession = false;
		}
	}
}
