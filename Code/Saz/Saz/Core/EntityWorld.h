#pragma once

#include <Saz/Core/Core.h>
#include <Saz/TypeId.h>

#include <Core/DynamicArray.h>

#include <entt/entt.hpp>
#include <Saz/Core/Entity.h>

namespace Saz
{
	class GameTime;
}

namespace ecs
{
	class System;

	struct ComponentEntry
	{
		const Saz::TypeId m_TypeId = 0;
	};

	struct SystemEntry
	{
		const Saz::TypeId m_TypeId = 0;
		ecs::System* m_System = nullptr;
	};

	class EntityWorld
	{
	public:
		void Init();
		void PostInit();
		void Destroy();

		void Update(const Saz::GameTime& gameTime);
		void LateUpdate(const Saz::GameTime& gameTime);
		void ImGuiRender();

		bool IsAlive(const ecs::Entity& entity) const;

		auto CreateEntity()->ecs::Entity;
		void DestroyEntity(const ecs::Entity& entity);

		ecs::Entity TryGetEntityWithTag(const String& tag);

		template<class TComponent>
		bool HasComponent(const ecs::Entity& entity) const;

		template<class TComponent, typename... TArgs>
		auto GetComponent(const ecs::Entity& entity) -> TComponent&;

		template<typename... Components>
		auto GetAllEntitiesWith();

		template<class TComponent, typename... TArgs>
		auto TryGetComponent(const ecs::Entity& entity)->TComponent*;

		template<class TComponent>
		void RegisterComponent();

		template<class TComponent, typename... TArgs>
		auto AddComponent(const ecs::Entity& entity, TArgs&&... args) -> TComponent&;

		template<class TComponent>
		void RemoveComponent(const ecs::Entity& entity);

		template<class TComponent, typename Type>
		void SubscribeToComponentAdd(const ecs::Entity& entity, TComponent& component, Type&& func);

		template<class TSystem>
		auto GetSystem()->TSystem&;

		template<class TSystem, typename... TArgs>
		void RegisterSystem(TArgs&&... args);

		void DestroyAllEntities();

		ecs::Entity GetMainCameraEntity();

	public:
		entt::registry m_Registry;

	protected:
		DynamicArray<ComponentEntry> m_ComponentEntries;
		DynamicArray<SystemEntry> m_SystemEntries;
	};
}

#include "EntityWorld.inl"