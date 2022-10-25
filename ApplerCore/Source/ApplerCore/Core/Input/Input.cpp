#include "arpch.h"
#include "Input.h"

namespace Appler
{
	std::unordered_map<int, int> Input::m_KeyStates;
	std::unordered_map<int, int> Input::m_MouseStates;

	Events::EventListener<int, int> Input::m_KeyPressedListener;
	Events::EventListener<int> Input::m_KeyReleasedListener;
	Events::EventListener<int, int> Input::m_MouseButtonPressedListener;

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

	bool Input::IsMouseButtonHeld(MouseCode mousecode)
	{
		if (!m_MouseStates.contains((int)mousecode)) return false;
		if (m_MouseStates[(int)mousecode] == 1 || m_MouseStates[(int)mousecode] == -1) return true;

		return false;
	}

	bool Input::IsMouseButtonPressed(MouseCode mousecode)
	{
		if (!m_MouseStates.contains((int)mousecode)) return false;
		if (m_MouseStates[(int)mousecode] == 1)
		{
			m_MouseStates[(int)mousecode] = -1;
			return true;
		}

		return false;
	}

	bool Input::IsMouseButtonReleased(MouseCode mousecode)
	{
		if (!m_MouseStates.contains((int)mousecode)) return false;
		if (m_MouseStates[(int)mousecode] == 0)
		{
			m_MouseStates[(int)mousecode] = -2;
			return true;
		}

		return false;
	}

	void Input::Constructor(Application* application)
	{
		m_KeyPressedListener.OnCallback = OnKeyPressed;
		m_KeyReleasedListener.OnCallback = OnKeyReleased;
		m_MouseButtonPressedListener.OnCallback = OnMouseButtonPressed;

		application->GetDisplay()->GetDisplayData().KeyPressedEvent += m_KeyPressedListener;
		application->GetDisplay()->GetDisplayData().KeyReleasedEvent += m_KeyReleasedListener;
		application->GetDisplay()->GetDisplayData().MouseButtonPressedEvent += m_MouseButtonPressedListener;
	}

	void Input::OnKeyPressed(int key, int state)
	{
		m_KeyStates[key] = state;
	}

	void Input::OnKeyReleased(int key)
	{
		m_KeyStates[key] = 2;
	}

	void Input::OnMouseButtonPressed(int key, int state)
	{
		m_MouseStates[key] = state;
	}
}