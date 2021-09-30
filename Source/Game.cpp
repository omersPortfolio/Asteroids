#include "GamePCH.h"

#include "Game.h"
#include "Core/World.h"
#include "Core/Log.h"
#include "Managers/ResourceManager.h"

Game::Game()
{
	m_pLog = new fw::Log();
	m_pResourceManager = new ResourceManager();
	//m_Managers.push_back(m_pResourceManager);
	//m_Managers.push_back(m_pComponentManager);
	m_pWorld = new World(this);

	
}

Game::~Game()
{
	delete m_pLog;
	delete m_pResourceManager;
	delete m_pWorld;
}

void Game::Init()
{
	sf::Texture* pShipTexture = new sf::Texture();
	m_pResourceManager->LoadTexture("Ship.png", pShipTexture);
	
	m_pWorld->Init();
	LOG(INFO, "World Initialized...");
}

void Game::Destroy()
{

}

void Game::Update(float deltaTime)
{

	m_pWorld->Update(deltaTime);

	fw::Log::Update();
}

void Game::Draw(sf::RenderWindow* window)
{
	m_pWorld->Draw(window);
}
