#include "FrameworkPCH.h"

#include "SpriteSystem.h"
#include "SpriteComponent.h"
#include "TransformComponent.h"

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include <entt/entt.hpp>
#include "PlayerComponent.h"

namespace ecs
{
	void SpriteSystem::OnPlayerComponentAdded(entt::registry& registry, entt::entity entity)
	{
		SpriteComponent& spriteComp = registry.get<SpriteComponent>(entity);
		sf::Texture* texture = new sf::Texture();
		if (texture->loadFromFile("D:/Dev/MyFramework/Code/Game/Data/Textures/Ship.png"))
		{
			spriteComp.m_pTexture = texture;
		}
	}

	SpriteSystem::SpriteSystem(sf::RenderWindow& window)
		: m_Window(window)
	{
		
	}

	void SpriteSystem::Init()
	{
		m_pWorld->m_Registry.on_construct<SpriteComponent>().connect<&SpriteSystem::OnPlayerComponentAdded>(this);
	}

	SpriteSystem::~SpriteSystem()
	{
		m_pWorld->m_Registry.on_construct<SpriteComponent>().disconnect<&SpriteSystem::OnPlayerComponentAdded>(this);
		auto& registry = m_pWorld->m_Registry;

		auto view = registry.view<SpriteComponent>();
		for (const auto& entity : view)
		{
			SpriteComponent& spriteComp = view.get<SpriteComponent>(entity);
			delete spriteComp.m_pTexture;
		}
	}

	void SpriteSystem::Update(float deltaTime)
	{
		auto& registry = m_pWorld->m_Registry;

		const auto view = registry.view<TransformComponent, SpriteComponent>();
		for (const auto& entity : view)
		{
			SpriteComponent& spriteComp = view.get<SpriteComponent>(entity);
			TransformComponent& transformComp = view.get<TransformComponent>(entity);
			
			sf::Sprite sprite;
			sprite.setTexture(*spriteComp.m_pTexture);
			sprite.setPosition(sf::Vector2f(transformComp.m_Position.x, transformComp.m_Position.y));
		}
	}
}
