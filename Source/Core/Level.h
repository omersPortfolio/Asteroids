#pragma once

class Entity;

class Level
{
	friend class Entity;

public:
	Level(World& world);
	~Level();

public:
	virtual void Init();

	virtual void Update(float delta);

	virtual void Draw(sf::RenderWindow* pWindow);

	Entity CreateEntity(const std::string& name = std::string());

	World& GetWorld() { return m_World; }

	void LoadFromFile(const std::string& filename);

private:
	entt::registry m_Registry;

	World& m_World;
};