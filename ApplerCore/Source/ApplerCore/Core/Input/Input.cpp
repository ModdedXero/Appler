#include "arpch.h"
#include "Input.h"

namespace Appler
{
	std::unordered_map<int, int> Input::m_KeyStates;

	Events::EventListener<int, int> Input::m_KeyPressedListener;
	Events::EventListener<int> Input::m_KeyReleasedListener;

	bool Input::IsKeyHeld(KeyCode keycode)
	{
		if (!m_KeyStates.contains((int)keycode)) return false;
		if (m_KeyStates[(int)keycode] != 2 && m_KeyStates[(int)keycode] != -2) return true;

		return false;
	}

	bool Input::IsKeyPressed(KeyCode keycode)
	{
		if (!m_KeyStates.contains((int)keycode)) return false;
		if (m_KeyStates[(int)keycode] == 0)
		{
			m_KeyStates[(int)keycode] = -1;
			return true;
		}

		return false;
	}

	bool Input::IsKeyReleased(KeyCode keycode)
	{
		if (!m_KeyStates.contains((int)keycode)) return false;
		if (m_KeyStates[(int)keycode] == 2)
		{
			m_KeyStates[(int)keycode] = -2;
			return true;
		}

		return false;
	}

	void Input::Constructor(Application* application)
	{
		m_KeyPressedListener.OnCallback = OnKeyPressed;
		m_KeyReleasedListener.OnCallback = OnKeyReleased;

		application->GetDisplay()->GetDisplayData().KeyPressedEvent += m_KeyPressedListener;
		application->GetDisplay()->GetDisplayData().KeyReleasedEvent += m_KeyReleasedListener;
	}

	void Input::OnKeyPressed(int key, int state)
	{
		m_KeyStates[key] = state;
	}

	void Input::OnKeyReleased(int key)
	{
		m_KeyStates[key] = 2;
	}
}