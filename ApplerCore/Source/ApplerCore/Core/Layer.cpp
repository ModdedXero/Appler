#include "arpch.h"
#include "Layer.h"

namespace Appler::Core
{
	Layer::Layer(const std::string& name)
		: m_DebugName(name)
	{
	}

	Layer::~Layer()
	{
	}
}