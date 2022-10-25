#include "arpch.h"
#include "Application.h"

#include <ApplerCore/Core/Input/Input.h>

namespace Appler
{
	Application::Application()
	{
		m_Display = new Display::NativeDisplay();

		// System Constructors

		Input::Constructor(this);
	}

	void Application::Run()
	{
		while (m_Display->IsRunning())
		{
			m_Display->OnUpdate();

			for (Layer* layer : m_LayerStack)
				layer->OnUpdate();

			glClearColor(1.0f, 0.5f, 0.4f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			m_Display->OnRender();
		}

		m_Display->OnDestroy();
	}

	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
	}

	void Application::PushOverlay(Layer* layer)
	{
		m_LayerStack.PushOverlay(layer);
	}
}