#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <string>

namespace ApplerCore::Display
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

	class NativeDisplay
	{
	public:
		void OnUpdate();
		void OnRender();
		void OnDestroy();

		bool IsRunning() { return !glfwWindowShouldClose(m_Window); }

		uint32_t GetWidth() { return m_Specs.Width; }
		uint32_t GetHeight() { return m_Specs.Height; }

		GLFWwindow* GetNativeWindow() { return m_Window; }

	private:
		GLFWwindow* m_Window;
		DisplaySpecs m_Specs;
	};
}