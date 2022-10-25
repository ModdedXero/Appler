#pragma once

#include <string>
#include <iostream>

namespace Appler
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

#define DEBUG_LOG(...)							Appler::Debug::Log("Application: ", __VA_ARGS__)
#define DEBUG_LOG_WARN(...)						Appler::Debug::LogWarn("Application: ", __VA_ARGS__)
#define DEBUG_LOG_ERROR(...)					Appler::Debug::LogError("Application: ", __VA_ARGS__)
											
#define DEBUG_CORE(...)							Appler::Debug::Log("Wyvern Engine: ", __VA_ARGS__)
#define DEBUG_CORE_WARN(...)					Appler::Debug::LogWarn("Wyvern Engine: ", __VA_ARGS__)
#define DEBUG_CORE_ERROR(...)					Appler::Debug::LogError("Wyvern Engine: ", __VA_ARGS__)
}