#include "pch.h"

#include "Log.h"

namespace Myth
{
	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

	void Log::Init()
	{
		spdlog::set_pattern("%^[%T][%n][%l](%t): %v%$");
		s_CoreLogger = spdlog::stdout_color_mt("MYTH-CORE");
		s_CoreLogger->set_level(spdlog::level::trace);

		s_ClientLogger = spdlog::stdout_color_mt("APP");
		s_CoreLogger->set_level(spdlog::level::trace);

	}
}
