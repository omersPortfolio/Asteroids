#pragma once

#include "System.h"

namespace Saz
{
	namespace sfml
	{
		class Window;
	}
}

namespace ecs 
{

	class SAZ_API InputSystem final : public System
	{
	public:
		
		InputSystem(Saz::sfml::Window& sfmlWindow);
		~InputSystem();

		virtual void Init() override;
		virtual void Update() override;

	private:
		Saz::sfml::Window& m_SFMLWindow;

		Set<Input::EKeyboard> m_KeyboardPrevious;
		Set<Input::EKeyboard> m_KeyboardCurrent;
		Set<Input::EMouse> m_MousePrevious;
		Set<Input::EMouse> m_MouseCurrent;
	};
}
