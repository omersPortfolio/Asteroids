#pragma once

#include "entt.hpp"

class ComponentManager;
class ResourceManager;
class Game;
class Level;

namespace sf
{
	class RenderWindow;
}

class Entity;

class World
{
public:
	World();
	~World();

public:
	virtual void Init();

	virtual void Update(float delta);

	virtual void Draw(sf::RenderWindow* pWindow);

	ResourceManager* GetResourceManager();

private:

	ResourceManager* m_pResourceManager = nullptr;

	Level* m_pLevel = nullptr;

	friend class Entity;
};