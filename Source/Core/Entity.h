#pragma once

#include "Core/World.h"
#include "entt.hpp"

class Entity
{
public:
	Entity() = default;
	Entity(entt::entity handle, World* pWorld);
	Entity(const Entity& other) = default;

	template<typename T, typename... Args>
	T& AddComponent(Args&&... args)
	{
		assert(!HasComponent<T>());
		return m_pWorld->m_Registry.emplace<T>(m_EntityHandle, std::forward<Args>(args)...);
	}

	template<typename T>
	T* GetComponent()
	{
		return m_pWorld->m_Registry.get<T>(m_EntityHandle);
	}

	template<typename T>
	bool HasComponent()
	{
		return m_pWorld->m_Registry.has<T>(m_EntityHandle);
	}

	template<typename T>
	void RemoveComponent()
	{
		assert(HasComponent<T>());
		m_pWorld->m_Registry.remove<T>(m_EntityHandle);
	}

	bool IsValid() const { return m_EntityHandle != entt::null; }

private:
	entt::entity m_EntityHandle = entt::null;
	World* m_pWorld = nullptr;
};