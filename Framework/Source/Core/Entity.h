#pragma once

#include "Core/Level.h"
#include <entt.hpp>

class Entity
{
public:
	Entity() = default;
	Entity(entt::entity handle, fw::Level* pLevel);
	Entity(const Entity& other) = default;

	template<typename T, typename... Args>
	T& AddComponent(Args&&... args)
	{
		assert(!HasComponent<T>());
		return m_pLevel->m_Registry.emplace<T>(m_EntityHandle, std::forward<Args>(args)...);
	}

	template<typename T>
	T* GetComponent()
	{
		return &m_pLevel->m_Registry.get<T>(m_EntityHandle);
	}

	template<typename T>
	bool HasComponent()
	{
		return m_pLevel->m_Registry.has<T>(m_EntityHandle);
	}

	template<typename T>
	void RemoveComponent()
	{
		assert(HasComponent<T>());
		m_pLevel->m_Registry.remove<T>(m_EntityHandle);
	}

	bool IsValid() const { return m_EntityHandle != entt::null; }

private:
	entt::entity m_EntityHandle = entt::null;
	fw::Level* m_pLevel = nullptr;
};