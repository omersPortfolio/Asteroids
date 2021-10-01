#pragma once

namespace sf
{
	class RenderWindow;
	class Clock;
}

namespace fw
{
	class GameCore;
	// This will handle all inputs, game loops etc.
	class FWCore
	{
	public:
		FWCore();
		virtual ~FWCore();

		void Init();
		void Destroy();

		void Run(GameCore* pGame);
		void Shutdown();

		//bool IsKeyDown();
		//bool IsMouseButtonDown(int id); etc

	private:

		sf::RenderWindow* m_pWindow = nullptr;
		sf::Clock* m_pClock = nullptr;

		GameCore* m_pGame = nullptr;
	};

}

