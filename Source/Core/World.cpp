#include "GamePCH.h"
#include "World.h"
#include "Managers/ResourceManager.h"
#include "Components/SpriteComponent.h"
#include "Game.h"
#include "Components/TransformComponent.h"
#include "Components/TagComponent.h"
#include "Level.h"

World::World()
{
	m_pResourceManager = new ResourceManager();

	m_pLevel = new Level(*this);
}

World::~World()
{
	delete m_pResourceManager;
	delete m_pLevel;
}

void World::Init()
{
	m_pLevel->Init();
	LOG(INFO, "Level initialized...");
}

void World::Update(float delta)
{
	m_pLevel->Update(delta);
}

void World::Draw(sf::RenderWindow* pWindow)
{
	m_pLevel->Draw(pWindow);
}

ResourceManager* World::GetResourceManager()
{
	return m_pResourceManager;
}
