#include "SazPCH.h"

#include "ResourceManager.h"

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/CircleShape.hpp>

#include <entt/entt.hpp>
#include <SFML/Graphics/Shape.hpp>

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
		for (const auto& [name, shape] : m_Shapes)
		{
			delete shape;
		}
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

		return m_Textures[filename];
	}

	const sf::Shape* ResourceManager::GetShape(const String& name)
	{
		return m_Shapes[name];
	}

	sf::RectangleShape* ResourceManager::CreateRectangle(const String& name, vec2 size, sf::Color color)
	{
		sf::RectangleShape* rectangle = new sf::RectangleShape(sf::Vector2f(size.x, size.y));
		rectangle->setFillColor(color);
		m_Shapes[name] = rectangle;

		return rectangle;
	}

	sf::CircleShape* ResourceManager::CreateCircle(const String& name, float radius, std::size_t pointCount)
	{
		sf::CircleShape* circle = new sf::CircleShape(radius, pointCount);
		m_Shapes[name] = circle;

		return circle;
	}

}