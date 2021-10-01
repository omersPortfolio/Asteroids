#include "FrameworkPCH.h"
#include "Level.h"

#include "Components/SpriteComponent.h"
#include "Components/TagComponent.h"
#include "Components/TransformComponent.h"
#include "Entity.h"
#include "Managers/ResourceManager.h"
#include "GameCore.h"

namespace fw
{
	Level::Level(GameCore* pGameCore)
	{
		m_pGameCore = pGameCore;
	}

	Level::~Level()
	{
	}

	void Level::Init()
	{
		
	}

	void Level::Update(float delta)
	{

	}

	void Level::Draw(sf::RenderWindow* pWindow)
	{
		
	}

	Entity Level::CreateEntity(const std::string& name /*= std::string()*/)
	{
		Entity entity{ m_Registry.create(), this };
		entity.AddComponent<TransformComponent>();
		auto& tagComp = entity.AddComponent<TagComponent>();
		tagComp.m_Tag = name.empty() ? "Entity" : name;

		return entity;
	}

	void Level::LoadFromFile(const std::string& filename)
	{

	}
}

