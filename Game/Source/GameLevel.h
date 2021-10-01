#pragma once

class Game;

class GameLevel : public fw::Level
{
public:
	GameLevel(fw::GameCore* pGameCore);
	virtual ~GameLevel();

	virtual void Init() override;

	virtual void Update(float delta) override;

	virtual void Draw(sf::RenderWindow* pWindow) override;

	Game* GetGame();

private:
	void OnSpriteComponentAdded(entt::registry& registry, entt::entity entity);
};