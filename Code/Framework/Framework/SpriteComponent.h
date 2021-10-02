#pragma once

namespace sf
{
	class Texture;
	class Sprite;
}

struct SpriteComponent
{
	SpriteComponent() = default;

	SpriteComponent(const SpriteComponent&) = default;

	sf::Texture* m_pTexture = nullptr;
};
