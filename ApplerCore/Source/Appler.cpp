#include "arpch.h"

#include <ApplerCore/Display/NativeDisplay.h>
#include <ApplerCore/Events/Event.h>

int main()
{
	ApplerCore::Display::NativeDisplay* display = new ApplerCore::Display::NativeDisplay();

	while (display->IsRunning())
	{
		display->OnUpdate();

		glClearColor(1.0f, 0.5f, 0.4f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		display->OnRender();
	}

	display->OnDestroy();

	return 0;
}