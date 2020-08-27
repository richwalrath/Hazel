#pragma once

// Assertions
#ifndef HZ_DEBUG
	#define HZ_ASSERTS 1
#endif

#if HZ_ASSERTS
	#define HZ_ASSERT(x, ...) { if(!(x)) { HZ_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define HZ_CORE_ASSERT(x, ...) { if(!(x)) { HZ_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define HZ_ASSERT(x, ...)
	#define HZ_CORE_ASSERT(x, ...)
#endif

// Profiling / Instrumentation

#define HZ_PROFILE 1
#if HZ_PROFILE
	#include "Hazel/Debug/Instrumentor.h"

	#define HZ_PROFILE_BEGIN_SESSION(name, filePath) ::Hazel::Instrumentor::Get().BeginSession(name, filePath)
	#define HZ_PROFILE_END_SESSION() ::Hazel::Instrumentor::Get().EndSession()
	#define HZ_PROFILE_SCOPE(name) ::Hazel::InstrumentationTimer timer##__LINE__(name)
	#define HZ_PROFILE_FUNCTION() HZ_PROFILE_SCOPE(__FUNCSIG__)

#else // Empty Macros

	#define HZ_PROFILE_BEGIN_SESSION(name, filePath)
	#define HZ_PROFILE_END_SESSION()
	#define HZ_PROFILE_SCOPE(name)
	#define HZ_PROFILE_FUNCTION()

#endif