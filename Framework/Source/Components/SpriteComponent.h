#pragma once

#include <string>

namespace sf
{
	class Texture;
	class Sprite;
}

struct SpriteComponent
{
	SpriteComponent() = default;
	SpriteComponent(sf::Texture* pTexture)
	: m_pTexture(pTexture) {}

	SpriteComponent(sf::Sprite* pSprite) 
		: m_pSprite(pSprite) {}
	SpriteComponent(const SpriteComponent&) = default;

	sf::Texture* m_pTexture = nullptr;
	sf::Sprite* m_pSprite = nullptr;
};
