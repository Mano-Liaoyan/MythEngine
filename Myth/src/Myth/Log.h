#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/fmt/ostr.h"

namespace Myth
{
	class MYTH_API Log
	{
	public:
		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger()
		{
			return s_CoreLogger;
		}

		inline static std::shared_ptr<spdlog::logger>& GetClientLogger()
		{
			return s_ClientLogger;
		}

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

#define MYTH_CORE_WARN(...) ::Myth::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define MYTH_CORE_INFO(...) ::Myth::Log::GetCoreLogger()->info(__VA_ARGS__)
#define MYTH_CORE_ERROR(...) ::Myth::Log::GetCoreLogger()->error(__VA_ARGS__)
#define MYTH_CORE_TRACE(...) ::Myth::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define MYTH_CORE_DEBUG(...) ::Myth::Log::GetCoreLogger()->debug(__VA_ARGS__)
#define MYTH_CORE_CRITICAL(...) ::Myth::Log::GetCoreLogger()->critical(__VA_ARGS__)


#define MYTH_CLIENT_WARN(...) ::Myth::Log::GetClientLogger()->warn(__VA_ARGS__)
#define MYTH_CLIENT_INFO(...) ::Myth::Log::GetClientLogger()->info(__VA_ARGS__)
#define MYTH_CLIENT_ERROR(...) ::Myth::Log::GetClientLogger()->error(__VA_ARGS__)
#define MYTH_CLIENT_TRACE(...) ::Myth::Log::GetClientLogger()->trace(__VA_ARGS__)
#define MYTH_CLIENT_DEBUG(...) ::Myth::Log::GetClientLogger()->debug(__VA_ARGS__)
#define MYTH_CLIENT_CRITICAL(...) ::Myth::Log::GetClientLogger()->critical(__VA_ARGS__)
