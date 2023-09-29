#pragma once

#ifdef MYTH_PLATFORM_WINDOWS
	#ifdef MYTH_BUILD_DLL
		#define MYTH_API __declspec(dllexport)
	#else
		#define MYTH_API __declspec(dllimport)
	#endif
#else
	#error Myth Only Support Windows For Now!
#endif

#ifdef MYTH_ENABLE_ASSERTS
	#define MYTH_ASSERT(x, ...) { if(!(x))} { MYTH_CLIENT_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define MYTH_CORE_ASSERT(x, ...) { if(!(x))} { MYTH_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define MYTH_ASSERT(x, ...)
	#define MYTH_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << (x))
