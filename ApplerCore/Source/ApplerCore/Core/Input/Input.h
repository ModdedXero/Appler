#pragma once

#include "KeyCodes.h"
#include "MouseCodes.h"

#include <ApplerCore/Core/Application.h>
#include <ApplerCore/Events/Event.h>

namespace Appler::Core
{
	class Input
	{
		friend class Application;

	public:
		static bool IsKeyHeld(KeyCode keycode);
		static bool IsKeyPressed(KeyCode keycode);
		static bool IsKeyReleased(KeyCode keycode);

		static bool IsMouseButtonHeld(MouseCode mousecode);
		static bool IsMouseButtonPressed(MouseCode mousecode);
		static bool IsMouseButtonReleased(MouseCode mousecode);

	private:
		static void Constructor(Application* application);

		static std::unordered_map<int, int> m_KeyStates;
		static std::unordered_map<int, int> m_MouseStates;

		static void OnKeyPressed(int key, int state);
		static void OnKeyReleased(int key);
		static void OnMouseButtonPressed(int key, int state);

		static Events::EventListener<int, int> m_KeyPressedListener;
		static Events::EventListener<int> m_KeyReleasedListener;
		static Events::EventListener<int, int> m_MouseButtonPressedListener;
	};
}