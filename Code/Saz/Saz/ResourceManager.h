#pragma once

namespace sf
{
	class Texture;
}

namespace Saz
{
	class ResourceManager final
	{
	public:
		ResourceManager();
		~ResourceManager();

		const sf::Texture& GetTexture(const String& name);
		const sf::Texture& LoadTexture(const String& filename);

	private:
		Map<String, sf::Texture> m_Textures;
	};
}
