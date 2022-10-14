#include "arpch.h"
#include "NativeDisplay.h"

namespace Appler::Display
{
	NativeDisplay::NativeDisplay(DisplaySpecs specs)
		: m_Window(nullptr)
	{
		m_DisplayData.Title = specs.Title;
		m_DisplayData.Width = specs.Width;
		m_DisplayData.Height = specs.Height;

		// Check if GLFW is Initialized
		if (!glfwInit())
		{
			// Log failed to init GLFW
			return;
		}

		m_Window = glfwCreateWindow(specs.Width, specs.Height, specs.Title, NULL, NULL);
		// WV_CORE_ASSERT(m_Window, "Failed to create GLFW Window instance!");

		glfwSetWindowAspectRatio(m_Window, 16, 9);

		glfwMakeContextCurrent(m_Window);
		gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

		glfwSetWindowUserPointer(m_Window, &m_DisplayData);

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		// GLFW Events

		glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
			{
				DisplayData& data = *(DisplayData*)glfwGetWindowUserPointer(window);

				switch (action)
				{
				case GLFW_PRESS:
				{
					data.KeyPressedEvent.Invoke(key, 0);
					break;
				}
				case GLFW_REPEAT:
				{
					data.KeyPressedEvent.Invoke(key, 1);
					break;
				}
				case GLFW_RELEASE:
				{
					data.KeyReleasedEvent.Invoke(key);
					break;
				}
				}
			});

		glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height)
			{
				DisplayData& data = *(DisplayData*)glfwGetWindowUserPointer(window);

				data.Width = width;
				data.Height = height;

				data.WindowResizeEvent.Invoke(width, height);
			});

		glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xpos, double ypos)
			{
				DisplayData& data = *(DisplayData*)glfwGetWindowUserPointer(window);

				data.MouseMovedEvent.Invoke(xpos, ypos);
			});

		glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods)
			{
				DisplayData& data = *(DisplayData*)glfwGetWindowUserPointer(window);

				data.MouseButtonPressedEvent.Invoke(button, action);
			});

		glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xoffset, double yoffset)
			{
				DisplayData& data = *(DisplayData*)glfwGetWindowUserPointer(window);

				data.MouseScrolledEvent.Invoke(yoffset);
			});
	}

	void NativeDisplay::OnUpdate()
	{
		glfwPollEvents();
	}

	void NativeDisplay::OnRender()
	{
		glfwSwapBuffers(m_Window);
	}

	void NativeDisplay::OnDestroy()
	{
		glfwTerminate();
	}
}