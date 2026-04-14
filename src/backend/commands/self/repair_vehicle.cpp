#include "backend/command.hpp"
#include "util/vehicle.hpp"

namespace big
{
	class repairpv : command
	{
		using command::command;

		virtual void execute(const command_arguments&, const std::shared_ptr<command_context> ctx) override
		{
			vehicle::repair(self::veh);
		}
	};

	repairpv g_repairpv("repairpv", "REPARAR_VEHICULO_PERSONAL", "REPARAR_VEHICULO_PERSONAL_DESC", 0);
}