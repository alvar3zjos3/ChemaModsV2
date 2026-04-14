#include "backend/command.hpp"
#include "script_global.hpp"
#include "util/mobile.hpp"

namespace big
{
	class boat_pickup : command
	{
		using command::command;

		virtual void execute(const command_arguments&, const std::shared_ptr<command_context> ctx) override
		{
			mobile::merry_weather::request_boat_pickup();
		}
	};

	class ballistic_armor : command
	{
		using command::command;

		virtual void execute(const command_arguments&, const std::shared_ptr<command_context> ctx) override
		{
			mobile::ceo_abilities::request_ballistic_armor();
		}
	};

	class request_avenger : command
	{
		using command::command;

		virtual void execute(const command_arguments&, const std::shared_ptr<command_context> ctx) override
		{
			mobile::services::request_avenger();
		}
	};

	class request_kosatka : command
	{
		using command::command;

		virtual void execute(const command_arguments&, const std::shared_ptr<command_context> ctx) override
		{
			mobile::services::request_kosatka();
		}
	};

	class request_moc : command
	{
		using command::command;

		virtual void execute(const command_arguments&, const std::shared_ptr<command_context> ctx) override
		{
			mobile::services::request_mobile_operations_center();
		}
	};

	class request_terrorbyte : command
	{
		using command::command;

		virtual void execute(const command_arguments&, const std::shared_ptr<command_context> ctx) override
		{
			mobile::services::request_terrorbyte();
		}
	};

	class request_acidlab : command
	{
		using command::command;

		virtual void execute(const command_arguments&, const std::shared_ptr<command_context> ctx) override
		{
			mobile::services::request_acidlab();
		}
	};

	class request_acidlab_bike : command
	{
		using command::command;

		virtual void execute(const command_arguments&, const std::shared_ptr<command_context> ctx) override
		{
			mobile::services::request_acidlab_bike();
		}
	};

	class request_taxi : command
	{
		using command::command;

		virtual void execute(const command_arguments&, const std::shared_ptr<command_context> ctx) override
		{
			mobile::mobile_misc::request_taxi();
		}
	};

	class request_gun_van : command
	{
		using command::command;

		virtual void execute(const command_arguments&, const std::shared_ptr<command_context> ctx) override
		{
			mobile::mobile_misc::request_gun_van();
		}
	};

	boat_pickup g_boat_pickup("boatpickup", "SOLICITAR_BOTE", "SOLICITAR_BOTE_DESC", 0);
	ballistic_armor g_ballistic_armor("ballisticarmor", "SOLICITAR_ARMADURA_BALISTICA", "SOLICITAR_ARMADURA_BALISTICA_DESC", 0);
	request_avenger g_request_avenger("avenger", "SOLICITAR_AVENGER", "SOLICITAR_AVENGER_DESC", 0);
	request_kosatka g_request_kosatka("kosatka", "SOLICITAR_KOSATKA", "SOLICITAR_KOSATKA_DESC", 0);
	request_moc g_request_moc("moc", "SOLICITAR_MOC", "SOLICITAR_MOC_DESC", 0);
	request_terrorbyte g_request_terrorbyte("terrorbyte", "SOLICITAR_TERRORBYTE", "SOLICITAR_TERRORBYTE_DESC", 0);
	request_acidlab g_request_acidlab("acidlab", "SOLICITAR_ACID_LAB", "SOLICITAR_ACID_LAB_DESC", 0);
	request_acidlab_bike g_request_acidlab_bike("acidbike", "SOLICITAR_BICI_ACID", "SOLICITAR_BICI_ACID_DESC", 0);
	request_taxi g_request_taxi("taxi", "SOLICITAR_TAXI", "SOLICITAR_TAXI_DESC", 0);
	request_gun_van g_request_gun_van("gunvan", "SOLICITAR_GUN_VAN", "SOLICITAR_GUN_VAN_DESC", 0);
}