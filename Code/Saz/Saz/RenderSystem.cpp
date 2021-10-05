#include "SazPCH.h"

#include "Saz/RenderSystem.h"
#include "Saz/SpriteComponent.h"
#include "Saz/TransformComponent.h"

#include "GLFW/Window.h"

#include "SFML/Window.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Texture.hpp>

#include <entt/entt.hpp>

namespace ecs
{	
	RenderSystem::RenderSystem(Saz::sfml::Window& sfmlWindow)
		: m_SFMLWindow(sfmlWindow)
	{
	
	}

	RenderSystem::~RenderSystem()
	{
		auto& registry = m_World->m_Registry;
		for (const ecs::Entity& view : registry.view<SpriteComponent>())
		{
			const auto& spriteComponent = registry.get<SpriteComponent>(view);
			delete spriteComponent.m_Texture;
		}
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

		const auto spriteView = registry.view<SpriteComponent, TransformComponent>();
		for (const ecs::Entity& view : spriteView)
		{
			const auto& spriteComponent = spriteView.get<SpriteComponent>(view);
			const auto& transformComponent = spriteView.get<TransformComponent>(view);

			if (!spriteComponent.m_Texture)
				continue;

			sf::Sprite sprite;
			sprite.setTexture(*spriteComponent.m_Texture);
			sprite.setPosition(transformComponent.m_Position.x, transformComponent.m_Position.y);

			m_SFMLWindow.m_Texture.draw(sprite);
		}
	}

}
