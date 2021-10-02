#include "FrameworkPCH.h"
#include "Input.h"

bool Input::IsKeyPressed(sf::Keyboard::Key key)
{
	return sf::Keyboard::isKeyPressed(key);
}

bool Input::IsMouseButtonPressed(sf::Mouse::Button button)
{
	return sf::Mouse::isButtonPressed(button);
}

std::pair<float, float> Input::GetMousePosition(sf::RenderWindow* pWindow)
{
	return { (float)sf::Mouse::getPosition(*pWindow).x, (float)sf::Mouse::getPosition(*pWindow).y };
}

float Input::GetMouseX(sf::RenderWindow* pWindow)
{
	auto [x, y] = GetMousePosition(pWindow);
	return x;
}

float Input::GetMouseY(sf::RenderWindow* pWindow)
{
	auto [x, y] = GetMousePosition(pWindow);
	return y;
}
