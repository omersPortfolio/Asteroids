#include "GamePCH.h"

#include "GameLevel.h"
#include "Game.h"

namespace 
{
	static constexpr const char* playerTag = "Player";
}

void GameLevel::OnSpriteComponentAdded(entt::registry& registry, entt::entity entity)
{
	SpriteComponent& spriteComp = registry.get<SpriteComponent>(entity);
	spriteComp.m_pTexture = m_pGameCore->GetResourceManager()->GetTexture(spriteComp.m_TextureName);
	sf::Sprite& sprite = m_pGameCore->GetResourceManager()->CreateSprite(spriteComp.m_pTexture);
	spriteComp.m_pSprite = &sprite;

	TransformComponent& transformComp = registry.get<TransformComponent>(entity);
	spriteComp.m_pSprite->setPosition(sf::Vector2f(transformComp.m_Position.x, transformComp.m_Position.y));
}

GameLevel::GameLevel(fw::GameCore* pGameCore)
	: fw::Level(pGameCore)
{
	m_Registry.on_construct<SpriteComponent>().connect<&GameLevel::OnSpriteComponentAdded>(this);
}

GameLevel::~GameLevel()
{
	m_Registry.on_construct<SpriteComponent>().disconnect<&GameLevel::OnSpriteComponentAdded>(this);
}

void GameLevel::Init()
{
	fw::Level::Init();

	Entity entity = CreateEntity("Player");
	if (TransformComponent* transformComp = entity.GetComponent<TransformComponent>())
		transformComp->m_Position = vec2(200.0f, 360.0f);

	entity.AddComponent<SpriteComponent>("Ship.png");

	LOG(INFO, "Level initialized...");
}

void GameLevel::Update(float delta)
{
	fw::Level::Update(delta);

	if (ImGui::Button("Log Components"))
	{
		auto view = View<PlayerComponent>();
		for (const auto& entity : view)
		{
			LOG(WARNING, "Player:PlayerComponent");

			if (m_Registry.has<TransformComponent>(entity))
				LOG(WARNING, "Player:TransformComponent");
			if (m_Registry.has<SpriteComponent>(entity))
				LOG(WARNING, "Player:SpriteComponent");
			if (m_Registry.has<TagComponent>(entity))
				LOG(WARNING, "Player:TagComponent");
		}
	}

	if (ImGui::Button("Set Random Position"))
	{
		auto view = View<PlayerComponent, TransformComponent>();
		for (const auto& entity : view)
		{
			TransformComponent& tranformComp = view.get<TransformComponent>(entity);

			tranformComp.m_Position = vec2(Math::RandomFloatInRange(50.0f, 500.0f), Math::RandomFloatInRange(50.0f, 600.0f));
			LOG(WARNING, "Position: %f, %f", tranformComp.m_Position.x, tranformComp.m_Position.y);
		}
	}
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
