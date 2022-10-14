#pragma once

#include <ApplerCore/Display/NativeDisplay.h>

namespace Appler
{
	class Application
	{
	public:
		Application();

		void Run();

		Display::NativeDisplay* GetDisplay() { return m_Display; }

	private:
		Display::NativeDisplay* m_Display;
	};
}