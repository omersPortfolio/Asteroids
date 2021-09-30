#include "GamePCH.h"
#include "Entity.h"

Entity::Entity(entt::entity handle, World* pWorld)
	: m_EntityHandle(handle)
	, m_pWorld(pWorld)
{
}