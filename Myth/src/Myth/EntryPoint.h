#pragma once

#ifdef MYTH_PLATFORM_WINDOWS

extern Myth::Application* CreateApplication();

inline int main(int argc,char** argv)
{
	Myth::Log::Init();
	MYTH_CORE_INFO("Initialized Core Logger!");
	MYTH_CLIENT_INFO("Initialized Client Logger!");

	const auto app = Myth::CreateApplication();
	app->Run();
	delete app;
}

#else
	#error Myth Only Support Windows For Now!
#endif