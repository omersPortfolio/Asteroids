#pragma once

#include <entt/entt.hpp>

namespace ecs
{
	class System;

	struct ComponentEntry
	{
		const core::TypeId m_TypeId = 0;
	};

	struct SystemEntry
	{
		const core::TypeId m_TypeId = 0;
		ecs::System* m_System = nullptr;
	};

	class EntityWorld
	{
	public:
		void Init();
		void Destroy();

		void Update(float deltaTime);

		bool IsAlive(const Entity& entity) const;

		auto CreateEntity()->ecs::Entity;
		void DestroyEntity(const Entity& entity);

		template<class TComponent>
		bool HasComponent(const Entity& entity) const;

		template<class TComponent, typename... TArgs>
		auto GetComponent(const Entity& entity) -> TComponent&;

		template<class TComponent>
		void RegisterComponent();

		template<class TComponent, typename... TArgs>
		auto AddComponent(const Entity& entity, TArgs&&... args) -> TComponent&;

		template<class TComponent>
		void RemoveComponent(const Entity& entity);

		template<class TSystem>
		auto GetSystem()->TSystem&;

		template<class TSystem, typename... TArgs>
		void RegisterSystem(TArgs&&... args);

	public:
		entt::registry m_Registry;

	protected:
		DynamicArray<ComponentEntry> m_ComponentEntries;
		DynamicArray<SystemEntry> m_SystemEntries;
	};
}

#include "EntityWorld.inl"