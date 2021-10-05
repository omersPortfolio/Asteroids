#pragma once

#include <Saz/Core.h>

#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

namespace spd {

	class SAZ_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

//Core log macros
#define SAZ_CORE_TRACE(...)		::spd::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define SAZ_CORE_INFO(...)		::spd::Log::GetCoreLogger()->info(__VA_ARGS__)
#define SAZ_CORE_WARN(...)		::spd::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define SAZ_CORE_ERROR(...)		::spd::Log::GetCoreLogger()->error(__VA_ARGS__)
#define SAZ_CORE_CRITICAL(...)	::spd::Log::GetCoreLogger()->critical(__VA_ARGS__)

//Client log macros
#define SAZ_TRACE(...)		::spd::Log::GetClientLogger()->trace(__VA_ARGS__)
#define SAZ_INFO(...)		::spd::Log::GetClientLogger()->info(__VA_ARGS__)
#define SAZ_WARN(...)		::spd::Log::GetClientLogger()->warn(__VA_ARGS__)
#define SAZ_ERROR(...)		::spd::Log::GetClientLogger()->error(__VA_ARGS__)
#define SAZ_CRITICAL(...)	::spd::Log::GetClientLogger()->critical(__VA_ARGS__)
