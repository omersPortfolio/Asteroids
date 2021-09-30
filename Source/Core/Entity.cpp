#include "GamePCH.h"
#include "Entity.h"

Entity::Entity(entt::entity handle, Level* pLevel)
	: m_EntityHandle(handle)
	, m_pLevel(pLevel)
{
}