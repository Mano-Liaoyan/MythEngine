#pragma once

#include "pch.h"

#include "Myth/Core.h"
#include "Myth/Events/Event.h"

namespace Myth
{
	struct WindowProperties
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		explicit WindowProperties(const std::string& title = "Myth Engine",
			const unsigned int width = 1920,
			const unsigned int height = 1080) :Title(title), Width(width), Height(height)
		{
		}
	};

	// Interface representation of a desktop system based Window
	class MYTH_API Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() = default;

		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		// Window Attributes
		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		static Window* Create(const WindowProperties& props = WindowProperties());
	};
}
