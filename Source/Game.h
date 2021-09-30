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

	ResourceManager* GetResourceManager() { return m_pResourceManager; }

	/*template<typename T>
	T* GetManager()
	{
		return dynamic_cast<Manager>(T);
	}*/

private:
	World* m_pWorld = nullptr;
	fw::Log* m_pLog = nullptr;

	ResourceManager* m_pResourceManager = nullptr;

	//std::set<Manager*> m_Managers;
};

