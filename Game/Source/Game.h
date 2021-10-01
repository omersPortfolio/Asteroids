#pragma once

namespace fw
{
	class ResourceManager;
}

class Game : public fw::GameCore
{
public:
	Game(fw::FWCore* pFramework);
	virtual ~Game();

	void Init();
	void Destroy();

	void Update(float deltaTime);
	void Draw(sf::RenderWindow* window);

private:
	Log* m_pLog = nullptr;
};

