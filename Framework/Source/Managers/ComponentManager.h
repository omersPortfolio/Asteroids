#pragma once

namespace sf
{
	class RenderWindow;
}

namespace fw 
{
	class GameCore;
	class Level;

	class ComponentManager
	{
	public:
		ComponentManager(GameCore* pGameCore);
		~ComponentManager();

		void Draw(sf::RenderWindow* pWindow);
		void Update(float deltaTime);

		Level* GetLevel();

	protected:
		GameCore* m_pGameCore;
		Level* m_pLevel;
	};
}
