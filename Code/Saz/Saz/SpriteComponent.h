#pragma once

#include <SFML/Graphics/Texture.hpp>

struct SpriteComponent
{
	SpriteComponent() = default;

	SpriteComponent(const SpriteComponent&) = default;

	sf::Texture* m_Texture;
};
