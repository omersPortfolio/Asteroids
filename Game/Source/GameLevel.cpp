#include "GamePCH.h"

#include "GameLevel.h"
#include "Game.h"

GameLevel::GameLevel(fw::GameCore* pGameCore)
	: fw::Level(pGameCore)
{

}

GameLevel::~GameLevel()
{

}

void GameLevel::Init()
{
	fw::Level::Init();

	Entity entity = CreateEntity("Player");
	SpriteComponent& spriteComp = entity.AddComponent<SpriteComponent>();
	spriteComp.m_pTexture = m_pGameCore->GetResourceManager()->GetTexture("Ship.png");
	sf::Sprite& pSprite = m_pGameCore->GetResourceManager()->CreateSprite(spriteComp.m_pTexture);
	spriteComp.m_pSprite = &pSprite;
	pSprite.setPosition(sf::Vector2f(50.0f, 360.0f));
}

void GameLevel::Update(float delta)
{
	fw::Level::Update(delta);

}

void GameLevel::Draw(sf::RenderWindow* pWindow)
{
	fw::Level::Draw(pWindow);

	auto view = View<SpriteComponent>();
	for (const auto& entity : view)
	{
		SpriteComponent& spriteComp = view.get<SpriteComponent>(entity);
		pWindow->draw(*spriteComp.m_pSprite);
	}
}

Game* GameLevel::GetGame()
{
	return static_cast<Game*>(m_pGameCore);
}
