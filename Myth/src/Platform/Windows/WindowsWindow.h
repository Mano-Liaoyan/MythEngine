#pragma once

#include "Myth/Window.h"

#include <GLFW/glfw3.h>


namespace Myth
{
	class WindowsWindow final :public Window
	{
	public:
		explicit WindowsWindow(const WindowProperties& props);
		~WindowsWindow() override;

		void OnUpdate() override;

		inline unsigned int GetWidth() const override { return m_Data.Width; }
		inline unsigned int GetHeight() const override { return m_Data.Height; }

		// Window Attributes
		inline void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EvenCallback = callback; }
		void SetVSync(bool enabled) override;
		bool IsVSync() const override;
	private:
		virtual void Init(const WindowProperties& props);
		virtual void Shutdown();

		GLFWwindow* m_Window;

		struct WindowData
		{
			std::string Title;
			unsigned int Width, Height;
			bool VSync;

			EventCallbackFn EvenCallback;
		};

		WindowData m_Data;

	};
}



