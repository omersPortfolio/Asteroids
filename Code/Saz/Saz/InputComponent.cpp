#include "SazPCH.h"
#include "InputComponent.h"

bool Input::InputComponent::IsKeyHeld(Input::EKeyboard key) const
{
	return m_KeyboardCurrent.count(key) > 0;
}

bool Input::InputComponent::IsKeyPressed(Input::EKeyboard key) const
{
	return m_KeyboardPrevious.count(key) == 0
		&& m_KeyboardCurrent.count(key) > 0;
}

bool Input::InputComponent::IsKeyReleased(Input::EKeyboard key) const
{
	return m_KeyboardPrevious.count(key) > 0
		&& m_KeyboardCurrent.count(key) == 0;
}

bool Input::InputComponent::IsKeyHeld(Input::EMouse key) const
{
	return m_MouseCurrent.count(key) > 0;
}

bool Input::InputComponent::IsKeyPressed(Input::EMouse key) const
{
	return m_MousePrevious.count(key) == 0
		&& m_MouseCurrent.count(key) > 0;
}

bool Input::InputComponent::IsKeyReleased(Input::EMouse key) const
{
	return m_MousePrevious.count(key) > 0
		&& m_MouseCurrent.count(key) == 0;
}