#pragma once

#include <string>
#include <iostream>
#include <filesystem>

namespace Appler::Core
{
	class Debug
	{
		struct expandType
		{
			template <typename T>
			expandType(T&&...) {}
		};
	public:
		template <typename... Args>
		static void Log(Args... args)
		{
			expandType{ 0, (std::cout << args, 0)... };
			std::cout << std::endl;
		}

		template <typename... Args>
		static void LogWarn(Args... args)
		{
			expandType{ 0, (std::cout << args, 0)... };
			std::cout << std::endl;
		}

		template <typename... Args>
		static void LogError(Args... args)
		{
			expandType{ 0, (std::cout << args, 0)... };
			std::cout << std::endl;
		}
	};
}

#define DEBUG_LOG(...)							Appler::Core::Debug::Log("Application: ", __VA_ARGS__)
#define DEBUG_LOG_WARN(...)						Appler::Core::Debug::LogWarn("Application: ", __VA_ARGS__)
#define DEBUG_LOG_ERROR(...)					Appler::Core::Debug::LogError("Application: ", __VA_ARGS__)
											
#define DEBUG_CORE(...)							Appler::Core::Debug::Log("Wyvern Engine: ", __VA_ARGS__)
#define DEBUG_CORE_WARN(...)					Appler::Core::Debug::LogWarn("Wyvern Engine: ", __VA_ARGS__)
#define DEBUG_CORE_ERROR(...)					Appler::Core::Debug::LogError("Wyvern Engine: ", __VA_ARGS__)

#ifdef AR_DEBUG
#if defined (AR_PLATFORM_WINDOWS)
#define AR_DEBUGBREAK() __debugbreak()
#else
#error "Platform doesn't support debugbreak yet!"
#endif
#endif

#ifdef AR_DEBUG
#define AR_ASSERT(check, ...) { if(!(check)) {DEBUG_LOG_ERROR("Assertion failed at ", std::filesystem::path(__FILE__).filename().string(), ":", __LINE__, " (", __VA_ARGS__, ")"); AR_DEBUGBREAK(); } }
#define AR_CORE_ASSERT(check, ...) { if(!(check)) {DEBUG_CORE_ERROR("Assertion failed at ", std::filesystem::path(__FILE__).filename().string(), ":", __LINE__, " (", __VA_ARGS__, ")"); AR_DEBUGBREAK(); } }
#else
#define AR_ASSERT(check, ...) {(check);}
#define AR_CORE_ASSERT(check, ...) {(check);}
#endif