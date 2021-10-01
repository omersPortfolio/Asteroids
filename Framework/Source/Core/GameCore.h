#pragma once

namespace sf
{
	class RenderWindow;
}

namespace fw
{
	class ResourceManager;
	class ComponentManager;
	class FWCore;
	class Level;

	class GameCore
	{
	public:
		GameCore(FWCore* pFramework);
		virtual ~GameCore();

		virtual void Update(float deltaTime) = 0;
		virtual void Draw(sf::RenderWindow* window) = 0;

		ResourceManager* GetResourceManager() { return m_pResourceManager; }

		sf::RenderWindow* GetWindow();

		Level* GetLevel() { return m_pLevel; }

	protected:
		FWCore* m_pFramework = nullptr;
		ResourceManager* m_pResourceManager = nullptr;
		ComponentManager* m_pComponentManager = nullptr;
		Level* m_pLevel = nullptr;
	};
}


