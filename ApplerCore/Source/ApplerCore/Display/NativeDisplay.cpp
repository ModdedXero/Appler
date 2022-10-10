#include "arpch.h"
#include "NativeDisplay.h"

namespace ApplerCore::Display
{
	NativeDisplay::NativeDisplay(DisplaySpecs specs)
		: m_Window(nullptr)
	{
		m_Specs.Title = specs.Title;
		m_Specs.Width = specs.Width;
		m_Specs.Height = specs.Height;

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
		glfwSetWindowUserPointer(m_Window, &m_Specs);

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
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