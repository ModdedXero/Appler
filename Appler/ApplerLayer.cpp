#include "ApplerLayer.h"

namespace Appler
{
	void ApplerLayer::OnAttach()
	{

	}

	void ApplerLayer::OnDetach()
	{

	}

	void ApplerLayer::OnUIRender()
	{
		bool show = true;
		ImGui::DockSpaceOverViewport();
		ImGui::ShowDemoWindow(&show);
	}
}