#include "arpch.h"
#include "Application.h"

#include <ApplerCore/Core/Input/Input.h>
#include <ApplerCore/ImGui/ImGuiLayer.h>

namespace Appler
{
	Application* Application::s_Application = nullptr;

	Application::Application()
	{
		s_Application = this;

		m_Display = new Display::NativeDisplay();
		m_ImGuiLayer = new ImGuiLayer();

		PushOverlay(m_ImGuiLayer);

		// System Constructors

		Input::Constructor(this);
	}

	void Application::Run()
	{
		while (m_Display->IsRunning())
		{
			m_Display->OnUpdate();

			// glClearColor(1.0f, 0.5f, 0.4f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			for (Layer* layer : m_LayerStack)
				layer->OnUpdate();

			m_ImGuiLayer->Begin();
			for (Layer* layer : m_LayerStack)
				layer->OnUIRender();
			m_ImGuiLayer->End();

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