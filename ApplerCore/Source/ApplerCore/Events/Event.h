#pragma once

#include <vector>
#include <functional>

namespace ApplerCore::Events
{
	template <typename ...Args>
	class EventListener
	{
	public:
		EventListener(std::function<void(Args...)> callback = nullptr)
			: OnCallback(callback)
		{}

		std::function<void(Args...)> OnCallback;
	};

	template <typename ...Args>
	class Event
	{
	public:
		template <typename ...Vars>
		void Invoke(Vars... vars)
		{
			for (auto listener : m_Listeners)
				listener->OnCallback(vars...);
		}

		void operator +=(EventListener<Args...>& listener)
		{
			m_Listeners.push_back(&listener);
		}

		void operator -=(EventListener<Args...>& listener)
		{
			for (int i = 0; i < m_Listeners.size(); i++)
			{
				if (m_Listeners[i] == &listener)
					m_Listeners.erase(m_Listeners.begin() + i);
			}
		}

	private:
		std::vector<EventListener<Args...>*> m_Listeners;
	};
}