#include "GamePCH.h"
#include "Level.h"
#include "Managers/ResourceManager.h"
#include "Components/SpriteComponent.h"
#include "Game.h"
#include "Components/TransformComponent.h"
#include "Components/TagComponent.h"

Level::Level(World& world)
	: m_World(world)
{
	
}

Level::~Level()
{
}

void Level::Init()
{
	Entity entity = CreateEntity("Player");
	SpriteComponent& spriteComp = entity.AddComponent<SpriteComponent>();
	spriteComp.m_pTexture = m_World.GetResourceManager()->GetTexture("Ship.png");
	sf::Sprite& pSprite = m_World.GetResourceManager()->CreateSprite(spriteComp.m_pTexture);
	spriteComp.m_pSprite = &pSprite;
	pSprite.setPosition(sf::Vector2f(50.0f, 360.0f));
}

void Level::Update(float delta)
{

}

void Level::Draw(sf::RenderWindow* pWindow)
{
	auto view = m_Registry.view<SpriteComponent>();
	for (const auto& entity : view)
	{
		SpriteComponent& spriteComp = view.get<SpriteComponent>(entity);
		pWindow->draw(*spriteComp.m_pSprite);
	}
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
