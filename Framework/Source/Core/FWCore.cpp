#include "FrameworkPCH.h"

#include "FWCore.h"
#include "GameCore.h"

namespace fw
{
	FWCore::FWCore()
	{
		
	}

	FWCore::~FWCore()
	{
		delete m_pClock;
		delete m_pWindow;
	}

	void FWCore::Init()
	{
		m_pClock = new sf::Clock();

		m_pWindow = new sf::RenderWindow(sf::VideoMode(1280, 720), "Game");
		ImGui::SFML::Init(*m_pWindow);
		m_pWindow->resetGLStates();

		
	}

	void FWCore::Destroy()
	{

	}

	void FWCore::Run(GameCore* pGame)
	{
		// Input handling, events etc.

		m_pGame = pGame;

		bool done = false;
		while (!done)
		{
			sf::Time deltaTime = m_pClock->restart();
			ImGui::SFML::Update(*m_pWindow, deltaTime);

			sf::Event event;
			while (m_pWindow->pollEvent(event))
			{
				ImGui::SFML::ProcessEvent(event);
				if (event.type == sf::Event::Closed)
				{
					m_pWindow->close();
					done = true;
				}
			}

			pGame->Update(deltaTime.asSeconds());

			m_pWindow->clear(sf::Color(200, 200, 100, 255));
			m_pGame->Draw(m_pWindow);
			ImGui::SFML::Render(*m_pWindow);
			m_pWindow->display();
		}
	}

	void FWCore::Shutdown()
	{
	}
}