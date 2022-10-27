#pragma once

#include <ApplerCore.h>

namespace Appler
{
	class ApplerLayer : public Appler::Core::Layer
	{
	public:
		void OnAttach() override;
		void OnDetach() override;
		void OnUIRender() override;

	};
}