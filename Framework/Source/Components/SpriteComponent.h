#pragma once

namespace sf
{
	class Texture;
	class Sprite;
}

struct SpriteComponent
{
	SpriteComponent() = default;
	SpriteComponent(const char* name)
	: m_TextureName(name) {}

	SpriteComponent(sf::Sprite* pSprite) 
		: m_pSprite(pSprite) {}
	SpriteComponent(const SpriteComponent&) = default;

	sf::Texture* m_pTexture = nullptr;
	const char* m_TextureName = nullptr;
	sf::Sprite* m_pSprite = nullptr;
};
