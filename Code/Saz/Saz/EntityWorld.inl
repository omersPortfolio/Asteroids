#pragma once

#include <Saz/TypeId.h>

inline bool ecs::EntityWorld::IsAlive(const Entity& entity) const
{
	return m_Registry.valid(entity);
}

inline auto ecs::EntityWorld::CreateEntity()->ecs::Entity
{
	return m_Registry.create();
}

inline void ecs::EntityWorld::DestroyEntity(const Entity& entity)
{
	m_Registry.destroy(entity);
}

template<class TComponent>
bool ecs::EntityWorld::HasComponent(const Entity& entity) const
{
	return m_Registry.has<TComponent>(entity);
}

template<class TComponent, typename... TArgs>
auto ecs::EntityWorld::GetComponent(const Entity& entity)->TComponent&
{
	assert(m_Registry.has<TComponent>(entity));
	return m_Registry.get<TComponent>(entity);
}

template<class TComponent>
void ecs::EntityWorld::RegisterComponent()
{
	static_assert(std::is_assignable<TComponent, TComponent>::value, "Component isn't assignable!");

	ComponentEntry entry =
	{
		core::ToTypeId<TComponent>()
	};

	//assert(!core::Contains(m_ComponentEntries, [&entry](const auto& lhs) { return lhs.m_TypeId == entry.m_TypeId; }));
	m_ComponentEntries.push_back(entry);
}

template<class TComponent, typename... TArgs>
auto ecs::EntityWorld::AddComponent(const Entity& entity, TArgs&&... args)->TComponent&
{
	assert(!m_Registry.has<TComponent>(entity));
	return m_Registry.emplace<TComponent>(entity, std::forward<TArgs>(args)...);
}

template<class TComponent>
void ecs::EntityWorld::RemoveComponent(const Entity& entity)
{
	assert(m_Registry.has<TComponent>(entity));
	m_Registry.remove<TComponent>(entity);
}

template<class TSystem>
TSystem& ecs::EntityWorld::GetSystem()
{
	constexpr core::TypeId typeId = core::ToTypeId<TSystem>();

	auto result = std::find_if(m_SystemEntries.begin(), m_SystemEntries.end(),
		[&typeId](const SystemEntry& entry)
		{
			return entry.m_TypeId == typeId;
		});

	assert(result != m_SystemEntries.end());
	return *dynamic_cast<TSystem*>(result->m_System);
}

template<class TSystem, typename... TArgs>
void ecs::EntityWorld::RegisterSystem(TArgs&&... args)
{
	static_assert(std::is_convertible<TSystem*, ecs::System*>::value, "System must inherit from ecs::System using the [public] keyword!");
	static_assert(std::is_base_of<ecs::System, TSystem>::value, "System isn't a base of ecs::System!");

	SystemEntry entry =
	{
		core::ToTypeId<TSystem>()
		, new TSystem(std::forward<TArgs>(args)...)
	};
	entry.m_System->m_pWorld = this;

	//assert(!core::Contains(m_SystemEntries, [&entry](const auto& lhs) { return lhs.m_TypeId == entry.m_TypeId; }));
	m_SystemEntries.push_back(entry);
}