#pragma once

#include "Layer.h"
#include "LayerStack.h"

#include <ApplerCore/Display/NativeDisplay.h>

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

	private:
		Display::NativeDisplay* m_Display;

		LayerStack m_LayerStack;
	};
}