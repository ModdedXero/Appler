#pragma once

#include "Layer.h"
#include "LayerStack.h"

#include <ApplerCore/Display/NativeDisplay.h>
#include <ApplerCore/ImGui/ImGuiLayer.h>

namespace Appler
{
	class Application
	{
	public:
		Application();

		void Run();

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		Display::NativeDisplay* GetDisplay() { return m_Display; }

	public:
		static Application* Get() { return s_Application; }

	private:
		static Application* s_Application;

		Display::NativeDisplay* m_Display;
		ImGuiLayer* m_ImGuiLayer;

		LayerStack m_LayerStack;
	};
}