#include "GamePCH.h"

#include "Game.h"
#include "GameLevel.h"

Game::Game(fw::FWCore* pFramework) : fw::GameCore(pFramework)
{
	
}

Game::~Game()
{
	delete m_pLog;
	delete m_pLevel;
	delete m_pResourceManager;
	delete m_pComponentManager;
}

void Game::Init()
{
	m_pResourceManager = new fw::ResourceManager();

	m_pLog = new fw::Log();

	sf::Texture* pShipTexture = new sf::Texture();
	m_pResourceManager->LoadTexture("Ship.png", pShipTexture);
	
	m_pLevel = new GameLevel(this);
	m_pLevel->Init(); 

	m_pComponentManager = new fw::ComponentManager(this);

	LOG(INFO, "Game Initialized...");
}

void Game::Destroy()
{

}
 
void Game::Update(float deltaTime)
{
	m_pComponentManager->Update(deltaTime);

	m_pLevel->Update(deltaTime);

	fw::Log::Update();
}

void Game::Draw(sf::RenderWindow* window)
{
	m_pComponentManager->Draw(window);

	m_pLevel->Draw(window);
}
