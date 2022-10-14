#pragma once

#include "KeyCodes.h"

#include <ApplerCore/Core/Application.h>
#include <ApplerCore/Events/Event.h>

namespace Appler
{
	class Input
	{
		friend class Application;

	public:
		static bool IsKeyHeld(KeyCode keycode);
		static bool IsKeyPressed(KeyCode keycode);
		static bool IsKeyReleased(KeyCode keycode);

		static bool IsMouseButtonHeld(KeyCode keycode);
		static bool IsMouseButtonPressed(KeyCode keycode);
		static bool IsMouseButtonReleased(KeyCode keycode);

	private:
		static void Constructor(Application* application);

		static std::unordered_map<int, int> m_KeyStates;

		static void OnKeyPressed(int key, int state);
		static void OnKeyReleased(int key);

		static Events::EventListener<int, int> m_KeyPressedListener;
		static Events::EventListener<int> m_KeyReleasedListener;
	};
}