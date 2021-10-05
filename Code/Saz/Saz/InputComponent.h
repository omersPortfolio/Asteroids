#pragma once

#include <Core/Input.h>

namespace Input
{
	struct InputComponent
	{
		bool IsKeyHeld(Input::EKeyboard key) const;
		bool IsKeyPressed(Input::EKeyboard key) const;
		bool IsKeyReleased(Input::EKeyboard key) const;

		bool IsKeyHeld(Input::EMouse key) const;
		bool IsKeyPressed(Input::EMouse key) const;
		bool IsKeyReleased(Input::EMouse key) const;

		Set<Input::EKeyboard> m_KeyboardPrevious;
		Set<Input::EKeyboard> m_KeyboardCurrent;
		Set<Input::EMouse> m_MousePrevious;
		Set<Input::EMouse> m_MouseCurrent;

		vec2 m_MouseDelta;
		vec2 m_MousePosition;
	};
}
