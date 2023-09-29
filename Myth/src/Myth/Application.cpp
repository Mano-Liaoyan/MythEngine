#include "Application.h"

#include "Log.h"
#include "Myth/Events/ApplicationEvent.h"

namespace Myth
{

	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		const WindowResizeEvent e(1920,1080);
		MYTH_CORE_TRACE(e);
		while (true)
		{

		}
	}
}
