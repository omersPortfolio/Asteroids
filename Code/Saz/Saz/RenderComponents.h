#pragma once

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/CircleShape.hpp>



namespace component
{
	struct SpriteComponent
	{
		sf::Texture m_Texture;
	};

	// #todo 
	union RenderComponent
	{
		sf::RectangleShape* m_RectangleShape;
		sf::CircleShape* m_CircleShape;
	};
}


