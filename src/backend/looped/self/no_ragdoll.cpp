#include "backend/looped_command.hpp"
#include "natives.hpp"

namespace big
{
	class no_ragdoll : looped_command
	{
		using looped_command::looped_command;

		virtual void on_tick() override
		{
			PED::SET_PED_CAN_RAGDOLL(self::ped, false);
		}

		virtual void on_disable() override
		{
			PED::SET_PED_CAN_RAGDOLL(self::ped, true);
		}
	};

	no_ragdoll g_no_ragdoll("noragdoll", "SIN_CAIDA", "NO_RAGDOLL_DESC", g.self.no_ragdoll);
}
