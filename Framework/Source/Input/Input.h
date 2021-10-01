#pragma once

namespace sf
{
	class RenderWindow;
	class Mouse;
	class Keyboard;
	enum Key;
	enum Button;
}

class Input
{
public:
	static bool IsKeyPressed(sf::Keyboard::Key key);

	static bool IsMouseButtonPressed(sf::Mouse::Button button);
	static std::pair<float, float> GetMousePosition(sf::RenderWindow* pWindow);
	static float GetMouseX(sf::RenderWindow* pWindow);
	static float GetMouseY(sf::RenderWindow* pWindow);
};