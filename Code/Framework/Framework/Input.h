#pragma once

#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics/RenderWindow.hpp>


class Input
{
public:
	static bool IsKeyPressed(sf::Keyboard::Key key);

	static bool IsMouseButtonPressed(sf::Mouse::Button button);
	static std::pair<float, float> GetMousePosition(sf::RenderWindow* pWindow);
	static float GetMouseX(sf::RenderWindow* pWindow);
	static float GetMouseY(sf::RenderWindow* pWindow);
};