#include "SazPCH.h"

#include "Saz/RenderSystem.h"
#include "Saz/RenderComponents.h"
#include "Saz/TransformComponent.h"

#include "SFML/Window.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Shape.hpp>
#include <SFML/Graphics/Transformable.hpp>

#include <entt/entt.hpp>
#include "RenderComponents.h"

namespace ecs
{	
	RenderSystem::RenderSystem(Saz::sfml::Window& sfmlWindow)
		: m_SFMLWindow(sfmlWindow)
	{
	
	}

	RenderSystem::~RenderSystem()
	{
	}

	void RenderSystem::Init()
	{
		
	}

	void RenderSystem::Update()
	{
		RenderSFML();
	}

	void RenderSystem::RenderSFML()
	{
		auto& registry = m_World->m_Registry;

		const auto spriteView = registry.view<component::SpriteComponent, component::TransformComponent>();
		for (const ecs::Entity& view : spriteView)
		{
			const auto& spriteComponent = spriteView.get<component::SpriteComponent>(view);
			const auto& transformComponent = spriteView.get<component::TransformComponent>(view);

			const sf::Texture& texture = spriteComponent.m_Texture;

			sf::Sprite sprite;
			sprite.setTexture(spriteComponent.m_Texture);
			sprite.setPosition(transformComponent.m_Position.x, transformComponent.m_Position.y);
			sprite.setScale(transformComponent.m_Scale.x, transformComponent.m_Scale.x * -1.0f);
			sprite.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);

			m_SFMLWindow.m_Texture.draw(sprite);
		}

		const auto renderView = registry.view<component::RenderComponent, component::TransformComponent>();
		for (const ecs::Entity& view : renderView)
		{
			const auto& renderComp = renderView.get<component::RenderComponent>(view);
			const auto& transformComponent = renderView.get<component::TransformComponent>(view);
			
			if (renderComp.m_RectangleShape)
			{
				renderComp.m_RectangleShape->setPosition(transformComponent.m_Position.x, transformComponent.m_Position.y);
				m_SFMLWindow.m_Texture.draw(*renderComp.m_RectangleShape);
			}
			else if (renderComp.m_CircleShape)
			{
				renderComp.m_CircleShape->setPosition(transformComponent.m_Position.x, transformComponent.m_Position.y);
				m_SFMLWindow.m_Texture.draw(*renderComp.m_CircleShape);
			}
		}
	}
}
