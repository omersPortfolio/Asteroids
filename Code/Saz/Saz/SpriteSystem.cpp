#include "SazPCH.h"

#include "SpriteSystem.h"
#include "SpriteComponent.h"
#include "TransformComponent.h"

#include <entt/entt.hpp>
#include "PlayerComponent.h"

namespace ecs
{
	void SpriteSystem::OnPlayerComponentAdded(entt::registry& registry, entt::entity entity)
	{
		SpriteComponent& spriteComp = registry.get<SpriteComponent>(entity);
		
	}

	SpriteSystem::SpriteSystem(Saz::Window& window)
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
		}
	}

	void SpriteSystem::Update()
	{
		/*auto& registry = m_pWorld->m_Registry;

		const auto view = registry.view<TransformComponent, SpriteComponent>();
		for (const auto& entity : view)
		{
			SpriteComponent& spriteComp = view.get<SpriteComponent>(entity);
			TransformComponent& transformComp = view.get<TransformComponent>(entity);
		}*/
	}
}
