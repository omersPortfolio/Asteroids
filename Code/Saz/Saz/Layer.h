#pragma once

#include <Saz/Core.h>
#include <Saz/Events/Event.h>
#include "Core/String.h"

namespace Saz
{
	class SAZ_API Layer
	{
	public:
		Layer(const String& debugName = "Layer");
		virtual ~Layer();

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate() {}
		virtual void OnImGuiRender() {}
		virtual void OnEvent(Event& event) {}

		inline const String& GetName() const { return m_DebugName; }
	protected:
		String m_DebugName;
	};
}