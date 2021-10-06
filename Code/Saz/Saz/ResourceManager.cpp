#include "SazPCH.h"

#include "ResourceManager.h"
#include <SFML/Graphics/Texture.hpp>

#include <entt/entt.hpp>

namespace
{
	// #todo
	const String initialPath = "D:/Dev/Saz/Data/Textures/";
}

namespace Saz
{
	ResourceManager::ResourceManager()
	{

	}

	ResourceManager::~ResourceManager()
	{
		
	}

	const sf::Texture& ResourceManager::GetTexture(const String& name)
	{
		SAZ_ASSERT((m_Textures.find(name) != m_Textures.end()), "No texture found with the given name! It might not be loaded yet!");
		return m_Textures[name];
	}

	const sf::Texture& ResourceManager::LoadTexture(const String& filename)
	{
		sf::Texture texture;
		bool loadSuccess = texture.loadFromFile(initialPath + filename);
		SAZ_ASSERT(loadSuccess, "Texture is not loaded. Make sure the file path is correct!");
		if (loadSuccess)
			m_Textures[filename] = texture;

		return texture;
	}
}