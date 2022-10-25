#pragma once

namespace Appler
{
	class Timestep
	{
		friend class Application;
	public:
		static float GetSeconds() { return m_Time; }
		static float GetMilliseconds() { return m_Time * 1000; }
		static float GetDeltaTime() { return m_DeltaTime * m_TimeScale; }
		static float GetFPS() { return 1 / m_DeltaTime; }
		static float GetFixedDeltaTime() { return 0.2f * m_TimeScale; }

		static void SetTimeScale(float scale) { m_TimeScale = scale; }

		operator float() const { return m_Time; }
	protected:
		static inline float m_Time = 0;
		static inline float m_DeltaTime = 0;
		static inline float m_TimeScale = 1.0f;
	};
}