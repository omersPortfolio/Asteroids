#include "FrameworkPCH.h"
#include "EntityWorld.h"
#include "System.h"

namespace ecs
{
	void EntityWorld::Init()
	{
		for (ecs::SystemEntry& entry : m_SystemEntries)
			entry.m_System->Init();
	}

	void EntityWorld::Destroy()
	{
		m_ComponentEntries.clear();
		for (ecs::SystemEntry& entry : m_SystemEntries)
		{
			entry.m_System->Destroy();
			delete entry.m_System;
		}
		m_SystemEntries.clear();
	}

	void EntityWorld::Update(float deltaTime)
	{
		for (ecs::SystemEntry& entry : m_SystemEntries)
			entry.m_System->Update(deltaTime);
	}
}

