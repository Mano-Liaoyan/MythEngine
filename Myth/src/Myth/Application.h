#pragma once

#include "Core.h"

namespace Myth
{

	class MYTH_API Application
	{
	public:
		Application();

		virtual ~Application();

		void Run();

	private:

	};

	// To be defined in client
	Application* CreateApplication();
}

