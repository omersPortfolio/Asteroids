#include "GamePCH.h"
#include "World.h"
#include "Managers/ResourceManager.h"
#include "Components/SpriteComponent.h"
#include "Game.h"
#include "Components/TransformComponent.h"
#include "Components/TagComponent.h"

#pragma optimize("", off)

World::World(Game* pGame)
{
	m_pGame = pGame;

	sprite = new sf::Sprite();
}

World::~World()
{
}

void World::Init()
{
	Entity entity = CreateEntity("Player");
	SpriteComponent& spriteComp = entity.AddComponent<SpriteComponent>();
	spriteComp.m_pTexture = GetResourceManager()->GetTexture("Ship.png");
	sf::Sprite& pSprite = GetResourceManager()->CreateSprite(spriteComp.m_pTexture);
	spriteComp.m_pSprite = &pSprite;
	pSprite.setPosition(sf::Vector2f(50.0f, 360.0f));
}

void World::Update(float delta)
{
	
	
	
}

void World::Draw(sf::RenderWindow* pWindow)
{
	auto view = m_Registry.view<SpriteComponent>();
	for (const auto& entity : view)
	{
		SpriteComponent& spriteComp = view.get<SpriteComponent>(entity);
		pWindow->draw(*spriteComp.m_pSprite);
	}
}

Entity World::CreateEntity(const std::string& name /*= std::string()*/)
{
	Entity entity { m_Registry.create(), this };
	entity.AddComponent<TransformComponent>();
	auto& tagComp = entity.AddComponent<TagComponent>();
	tagComp.m_Tag = name.empty() ? "Entity" : name;
	
	return entity;
}


ResourceManager* World::GetResourceManager()
{
	return m_pGame->GetResourceManager();
}
