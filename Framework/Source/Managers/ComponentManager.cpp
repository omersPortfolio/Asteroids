#include "FrameworkPCH.h"

#include "ComponentManager.h"
#include "Components/SpriteComponent.h"
#include "Core/GameCore.h"
#include "Core/Level.h"
#include "Components/TransformComponent.h"

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
		auto view = m_pLevel->View<TransformComponent, SpriteComponent>();
		for (const auto& entity : view)
		{
			SpriteComponent& spriteComp = view.get<SpriteComponent>(entity);
			TransformComponent& transformComp = view.get<TransformComponent>(entity);
			spriteComp.m_pSprite->setPosition(sf::Vector2f(transformComp.m_Position.x, transformComp.m_Position.y));
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
