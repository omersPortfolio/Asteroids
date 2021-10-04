#pragma once

#include <Saz/Core.h>
#include "Layer.h"

namespace Saz
{
	class SAZ_API LayerStack
	{
	public:
		LayerStack();
		~LayerStack();

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
		void PopLayer(Layer* layer);
		void PopOverlay(Layer* overlay);

		DynamicArray<Layer*>::iterator begin() { return m_Layers.begin(); }
		DynamicArray<Layer*>::iterator end() { return m_Layers.end(); }
	private:
		DynamicArray<Layer*> m_Layers;
		DynamicArray<Layer*>::iterator m_LayerInsert;
	};
}