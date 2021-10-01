#include "FrameworkPCH.h"
#include "Entity.h"

Entity::Entity(entt::entity handle, fw::Level* pLevel)
	: m_EntityHandle(handle)
	, m_pLevel(pLevel)
{
}