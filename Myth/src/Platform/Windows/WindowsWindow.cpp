#include "pch.h"

#include "WindowsWindow.h"

#include "Myth/Events/ApplicationEvent.h"
#include "Myth/Events/MouseEvent.h"
#include "Myth/Events/KeyEvent.h"


namespace Myth
{
	static bool s_GLFWInitialized = false;

	static void GLFWErrorCallback(int error, const char* description)
	{
		MYTH_CORE_ERROR("(GLFW Error {0}): {1}", error, description);
	}

	Window* Window::Create(const WindowProperties& props)
	{
		return new WindowsWindow(props);
	}

	WindowsWindow::WindowsWindow(const WindowProperties& props)
	{
		WindowsWindow::Init(props);
	}


	WindowsWindow::~WindowsWindow()
	{
		WindowsWindow::Shutdown();
	}

	void WindowsWindow::Init(const WindowProperties& props)
	{
		m_Data.Title = props.Title;
		m_Data.Width = props.Width;
		m_Data.Height = props.Height;

		MYTH_CORE_INFO("Creating Window {0} ({1}, {2})", props.Title, props.Width, props.Height);

		if (!s_GLFWInitialized)
		{
			int success = glfwInit();
			MYTH_CORE_ASSERT(success, "GLFW initialized Failed!");
			glfwSetErrorCallback(GLFWErrorCallback);
			s_GLFWInitialized = true;
		}

		m_Window = glfwCreateWindow(static_cast<int>(props.Width), static_cast<int>(props.Height),
			m_Data.Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, &m_Data);
		SetVSync(true);

		// Set GLFW callbacks
		glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, const int width, const int height) {
			auto& [Title, Width, Height, VSync, EvenCallback]
				= *static_cast<WindowData*>(glfwGetWindowUserPointer(window));
			Width = width;
			Height = height;

			WindowResizeEvent event(width, height);
			EvenCallback(event);

		});

		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window) {
			auto& [Title, Width, Height, VSync, EvenCallback]
				= *static_cast<WindowData*>(glfwGetWindowUserPointer(window));
			WindowCloseEvent event;
			EvenCallback(event);

		});

		glfwSetKeyCallback(m_Window, [](GLFWwindow* window, const int key, int scanCode, const int action, int mods) {
			auto& [Title, Width, Height, VSync, EvenCallback]
				= *static_cast<WindowData*>(glfwGetWindowUserPointer(window));

			switch (action)
			{
				case GLFW_PRESS:
				{
					KeyPressedEvent event(key, 0);
					EvenCallback(event);
					break;
				}
				case GLFW_RELEASE:
				{
					KeyReleasedEvent event(key);
					EvenCallback(event);
					break;
				}
				case GLFW_REPEAT:
				{
					KeyPressedEvent event(key, 1);
					EvenCallback(event);
					break;
				}
				default:;
			}
		});

		glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, const int button, const int action, int mods) {
			auto& [Title, Width, Height, VSync, EvenCallback]
				= *static_cast<WindowData*>(glfwGetWindowUserPointer(window));

			switch (action)
			{
				case GLFW_PRESS:
				{
					MouseButtonPressedEvent event(button);
					EvenCallback(event);
					break;
				}
				case GLFW_RELEASE:
				{
					MouseButtonReleasedEvent event(button);
					EvenCallback(event);
					break;
				}
				default:;
			}
		});

		glfwSetScrollCallback(m_Window, [](GLFWwindow* window, const double xOffset, const double yOffset) {
			auto& [Title, Width, Height, VSync, EvenCallback]
				= *static_cast<WindowData*>(glfwGetWindowUserPointer(window));

			MouseScrolledEvent event(static_cast<float>(xOffset), static_cast<float>(yOffset));
			EvenCallback(event);

		});

		glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, const double xPosition, const double yPosition) {
			auto& [Title, Width, Height, VSync, EvenCallback]
				= *static_cast<WindowData*>(glfwGetWindowUserPointer(window));

			MouseMovedEvent event(static_cast<float>(xPosition), static_cast<float>(yPosition));
			EvenCallback(event);

		});


	}

	void WindowsWindow::Shutdown()
	{
		glfwDestroyWindow(m_Window);
	}

	void WindowsWindow::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

	void WindowsWindow::SetVSync(const bool enabled)
	{
		if (enabled)
		{
			glfwSwapInterval(1);
		}
		else
		{
			glfwSwapInterval(0);
		}

		m_Data.VSync = enabled;
	}

	bool WindowsWindow::IsVSync() const
	{
		return m_Data.VSync;
	}











}
