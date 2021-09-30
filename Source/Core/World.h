#pragma once

#include "entt.hpp"

class ComponentManager;
class ResourceManager;
class Game;

namespace sf
{
	class RenderWindow;
}

class Entity;

class World
{
public:
	World(Game* pGame);
	~World();

public:
	virtual void Init();

	virtual void Update(float delta);

	virtual void Draw(sf::RenderWindow* pWindow);

	Entity CreateEntity(const std::string& name = std::string());

	ResourceManager* GetResourceManager();

	Game* GetGame() { return m_pGame; }

	sf::Sprite* sprite = nullptr;

private:
	entt::registry m_Registry;

	Game* m_pGame = nullptr;

	friend class Entity;
};