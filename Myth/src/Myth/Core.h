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

class Core
{

};

