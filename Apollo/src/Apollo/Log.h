#pragma once
#include "Core.h"
#include "spdlog/spdlog.h"
#include <memory>


namespace Apollo {
	class APOLLO_API Log
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
//core log macros
#define AP_CORE_TRACE(...)  ::Apollo::Log::GetCoreLogger()->trace(va_args)
#define AP_CORE_INFO(...)   ::Apollo::Log::GetCoreLogger()->info(va_args)
#define AP_CORE_WARN(...)   ::Apollo::Log::GetCoreLogger()->warn(va_args)
#define AP_CORE_ERROR(...)  ::Apollo::Log::GetCoreLogger()->error(va_args)
#define AP_CORE_FATAL(...)  ::Apollo::Log::GetCoreLogger()->fatal(va_args)
 
//client log macros

#define AP_TRACE(...)       ::Apollo::Log::GetClientLogger()->trace(__VA_ARGS__)
#define AP_INFO(...)        ::Apollo::Log::GetClientLogger()->info(__VA_ARGS__)
#define AP_WARN(...)        ::Apollo::Log::GetClientLogger()->warn(__VA_ARGS__)
#define AP_ERROR(...)       ::Apollo::Log::GetClientLogger()->error(__VA_ARGS__)
#define AP_FATAL(...)       ::Apollo::Log::GetClientLogger()->fatal(__VA_ARGS__)


