#include "FrameworkPCH.h"

#include "ComponentManager.h"
#include "Components/SpriteComponent.h"
#include "Core/GameCore.h"
#include "Core/Level.h"
#include "Components/TransformComponent.h"
#include "Components/PlayerComponent.h"
#include "Input/Input.h"

namespace fw
{
	ComponentManager::ComponentManager(GameCore* pGameCore)
	{
		m_pLevel = pGameCore->GetLevel();
	}

	ComponentManager::~ComponentManager()
	{

	}

	void ComponentManager::Update(float deltaTime)
	{
		{
			auto view = m_pLevel->View<TransformComponent, SpriteComponent>();
			for (const auto& entity : view)
			{
				SpriteComponent& spriteComp = view.get<SpriteComponent>(entity);
				TransformComponent& transformComp = view.get<TransformComponent>(entity);
				spriteComp.m_pSprite->setPosition(sf::Vector2f(transformComp.m_Position.x, transformComp.m_Position.y));
			}
		}
		
		{
			auto view = m_pLevel->View<PlayerComponent, TransformComponent>();
			for (const auto& entity : view)
			{
				TransformComponent& transformComp = view.get<TransformComponent>(entity);
				PlayerComponent& playerComp = view.get<PlayerComponent>(entity);

				if (Input::IsKeyPressed(sf::Keyboard::W))
				{
					transformComp.m_Position.y -= 200.0f * deltaTime;
				}
				else if (Input::IsKeyPressed(sf::Keyboard::S))
				{
					transformComp.m_Position.y += 200.0f * deltaTime;
				}
			}
		}

	}

	fw::Level* ComponentManager::GetLevel()
	{
		return m_pGameCore->GetLevel();
	}

	void ComponentManager::Draw(sf::RenderWindow* pWindow)
	{
		auto view = m_pLevel->View<SpriteComponent>();
		for (const auto& entity : view)
		{
			SpriteComponent& spriteComp = view.get<SpriteComponent>(entity);
			pWindow->draw(*spriteComp.m_pSprite);
		}	
	}

}
