#pragma once

class World;
class Manager;
class ResourceManager;

namespace fw
{
	class Log;
}


class Game
{
public:
	Game();
	~Game();

	void Init();
	void Destroy();

	void Update(float deltaTime);
	void Draw(sf::RenderWindow* window);

private:
	World* m_pWorld = nullptr;
	fw::Log* m_pLog = nullptr;
};

