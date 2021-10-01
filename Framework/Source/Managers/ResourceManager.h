#pragma once

class Component;

namespace sf
{
	class Sprite;
	class RenderWindow;
}

namespace fw
{
	class Texture;

	class ResourceManager
	{
	public:
		ResourceManager();
		~ResourceManager();

		void LoadTexture(const std::string& fileName, sf::Texture* pTexture);

		sf::Texture* GetTexture(const std::string& name);

		void AddTexture(const std::string& name, sf::Texture* pTexture);
		sf::Sprite& CreateSprite(sf::Texture* pTexture = nullptr);

	protected:
		std::map<std::string, sf::Texture*> m_pTextures;
		std::vector<sf::Sprite*> m_Sprites;
	};
}

