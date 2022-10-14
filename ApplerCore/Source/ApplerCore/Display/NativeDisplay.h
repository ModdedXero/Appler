#pragma once

#include <ApplerCore/Events/Event.h>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <string>

namespace Appler::Display
{
	struct DisplaySpecs
	{
		const char* Title;
		uint32_t Width, Height;

		DisplaySpecs(const char* title = "Appler", uint32_t width = 1280, uint32_t height = 720)
			: Title(title), Width(width), Height(height)
		{
		}
	};

	struct DisplayData
	{
		std::string Title;
		uint32_t Width, Height;

		Events::Event<int, int> KeyPressedEvent;
		Events::Event<int> KeyReleasedEvent;
		Events::Event<double, double> MouseMovedEvent;
		Events::Event<int, int> MouseButtonPressedEvent;
		Events::Event<double> MouseScrolledEvent;
		Events::Event<uint32_t, uint32_t> WindowResizeEvent;
	};

	class NativeDisplay
	{
	public:
		NativeDisplay(DisplaySpecs specs = DisplaySpecs());

		void OnUpdate();
		void OnRender();
		void OnDestroy();

		bool IsRunning() { return !glfwWindowShouldClose(m_Window); }

		uint32_t GetWidth() { return m_DisplayData.Width; }
		uint32_t GetHeight() { return m_DisplayData.Height; }

		GLFWwindow* GetNativeWindow() { return m_Window; }
		DisplayData& GetDisplayData() { return m_DisplayData; }

	private:
		GLFWwindow* m_Window;
		DisplayData m_DisplayData;
	};
}