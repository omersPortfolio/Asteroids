#include "SazPCH.h"
#include "Layer.h"

namespace Saz
{
	Layer::Layer(const String& debugName)
		: m_DebugName(debugName)
	{
		OnAttach();
	}

	Layer::~Layer()
	{

	}

}