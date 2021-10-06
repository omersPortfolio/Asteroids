#include "GamePCH.h"

#include "Application.h"

#include <Saz/TransformComponent.h>
#include <Saz/InputComponent.h>
#include <Saz/SpriteComponent.h>
#include <Saz/ResourceManager.h>
#include <Saz/NameComponent.h>
#include <Saz/LevelSystem.h>
#include <Saz/SFML/Window.h>

#include <SFML/Graphics/Texture.hpp>
#include <entt/entt.hpp>

Application::Application()
{
	
}

Application::~Application()
{
	Destroy();
}

void Application::Init()
{
	Saz::Application::Init();

	m_pResourceManager->LoadTexture("Ship.png");
	m_pResourceManager->LoadTexture("Hollow_Knight.png");
	m_pResourceManager->LoadTexture("Island.png");

	ecs::LevelSystem& levelSystem = m_EntityWorld.GetSystem<ecs::LevelSystem>();
	levelSystem.LoadFromFile(FilePath("D:/Dev/Saz/Data/Scenes/DefaultScene.scene"));
}

void Application::Destroy()
{
	Saz::Application::Destroy();
}
 
void Application::Register()
{
	Saz::Application::Register();
}

void Application::Update()
{
	Saz::Application::Update();

	auto& registry = m_EntityWorld.m_Registry;
	const auto view = registry.view<component::TransformComponent, component::SpriteComponent, component::InputComponent>();
	for (const ecs::Entity& entity : view)
	{
		const auto& spriteComponent = view.get<component::SpriteComponent>(entity);
		auto& transformComponent = view.get<component::TransformComponent>(entity);
		auto& inputComponent = view.get<component::InputComponent>(entity);
		vec2& pos = transformComponent.m_Position;

		if (inputComponent.IsKeyHeld(Input::EKeyboard::A))
			pos.x -= 0.5f;
		if (inputComponent.IsKeyHeld(Input::EKeyboard::D))
			pos.x += 0.5f;
		if (inputComponent.IsKeyHeld(Input::EKeyboard::W))
			pos.y += 0.5f;
		if (inputComponent.IsKeyHeld(Input::EKeyboard::S))
			pos.y -= 0.5f;
	}

	ImGui::EndFrame();
}

Saz::Application* Saz::CreateApplication()
{
	return new ::Application();
}
