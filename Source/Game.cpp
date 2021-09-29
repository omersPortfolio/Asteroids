#include "GamePCH.h"

#include "Game.h"
#include "Core/World.h"
#include "Core/Log.h"

Game::Game()
{
	m_pLog = new fw::Log();

	m_pWorld = new World();
}

Game::~Game()
{
	delete m_pLog;
	delete m_pWorld;
}

void Game::Init()
{
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
	m_pWorld->Draw(*window);
}
