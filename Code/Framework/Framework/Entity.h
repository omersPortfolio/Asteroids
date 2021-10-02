#pragma once

#include <entt/entt.hpp>

namespace ecs
{
	using Entity = entt::entity;
}

//class Entity
//{
//public:
//	Entity() = default;
//	Entity(entt::entity handle, fw::World* pLevel);
//	Entity(const Entity& other) = default;
//
//	template<typename T, typename... Args>
//	T& AddComponent(Args&&... args)
//	{
//		assert(!HasComponent<T>());
//		return m_pLevel->m_Registry.emplace<T>(m_EntityHandle, std::forward<Args>(args)...);
//	}
//
//	template<typename T>
//	T* GetComponent()
//	{
//		return &m_pLevel->m_Registry.get<T>(m_EntityHandle);
//	}
//
//	template<typename T>
//	bool HasComponent()
//	{
//		return m_pLevel->m_Registry.has<T>(m_EntityHandle);
//	}
//
//	template<typename T>
//	void RemoveComponent()
//	{
//		assert(HasComponent<T>());
//		m_pLevel->m_Registry.remove<T>(m_EntityHandle);
//	}
//
//	bool IsValid() const { return m_EntityHandle != entt::null; }
//	entt::entity GetHandle() { return m_EntityHandle; }
//
//private:
//	entt::entity m_EntityHandle = entt::null;
//	fw::World* m_pLevel = nullptr;
//};