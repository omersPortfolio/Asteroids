#include "FrameworkPCH.h"
//#include "GameApplication.h"
//#include "Game.h"
//
//GameApplication::GameApplication()
//{
//	m_pClock = new sf::Clock();
//
//	m_pWindow = new sf::RenderWindow(sf::VideoMode(1280, 720), "Game");
//	ImGui::SFML::Init(*m_pWindow);
//	m_pWindow->resetGLStates();
//
//	m_pGame = new Game();
//}
//
//GameApplication::~GameApplication()
//{
//	delete m_pClock;
//	delete m_pWindow;
//	delete m_pGame;
//}
//
//bool GameApplication::Init()
//{
//	m_pGame->Init();
//	LOG(INFO, "Game Initialized...");
//	return true;
//}
//
//void GameApplication::Destroy()
//{
//	m_pGame->Destroy();
//	ImGui::SFML::Shutdown();
//}
//
//bool GameApplication::Update()
//{
//	sf::Time deltaTime = m_pClock->restart();
//	ImGui::SFML::Update(*m_pWindow, deltaTime);
//	m_pGame->Update(deltaTime.asSeconds());
//
//	sf::Event event;
//	while (m_pWindow->pollEvent(event))
//	{
//		ImGui::SFML::ProcessEvent(event);
//		if (event.type == sf::Event::Closed)
//		{
//			m_pWindow->close();
//			return false;
//		}
//	}
//
//	return true;
//}
//
//bool GameApplication::Draw()
//{
//	if (!m_pWindow->isOpen())
//		return false;
//
//	if (ImGui::Button("Update window title")) {
//		m_pWindow->setTitle("Button Clicked");
//	}
//
//	m_pWindow->clear(sf::Color(200, 200, 100, 255));
//	m_pGame->Draw(m_pWindow);
//	ImGui::SFML::Render(*m_pWindow);
//	m_pWindow->display();
//
//	return true;
//}
