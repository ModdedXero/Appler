#pragma once

#include <ApplerCore/Core/Timestep.h>
#include <ApplerCore/Core/Layer.h>

#include <Platform/OpenGL/ImGuiOpenGLRenderer.h>
#include <Platform/OpenGL/ImGuiGLFWRenderer.h>

namespace Appler
{
	class ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnAttach() override;
		void OnDetach() override;

		void OnUIRender() override;

		void Begin();
		void End();

		void SetDarkThemeColors();
		ImGuiContext* GetImGuiContext() { return m_ImGuiContext; }
	private:
		ImGuiContext* m_ImGuiContext;
	};
}