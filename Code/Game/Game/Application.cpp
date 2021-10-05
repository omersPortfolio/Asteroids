#include "GamePCH.h"

#include "Application.h"

#include <Saz/TransformComponent.h>
#include <Saz/InputComponent.h>
#include <Saz/SpriteComponent.h>

#include <SFML/Graphics/Texture.hpp>
#include <entt/entt.hpp>

Application::Application()
{
	
}

Application::~Application()
{
	
}

void Application::Init()
{
	Saz::Application::Init();	
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
	if (ImGui::Button("Create Entity with Sprite and Transform"))
	{
		ecs::Entity entity = m_EntityWorld.CreateEntity();
		sf::Texture* texture = new sf::Texture();
		if (texture->loadFromFile("D:/Dev/Saz/Code/Game/Data/Textures/Ship.png"))
		{
			SpriteComponent& spriteComp = m_EntityWorld.AddComponent<SpriteComponent>(entity);
			spriteComp.m_Texture = texture;
			TransformComponent& transformComp = m_EntityWorld.AddComponent<TransformComponent>(entity);
			transformComp.m_Position = vec2(600.0f, 360.0f);
		}
	}

	if (ImGui::Button("Add Input"))
	{
		const auto view = registry.view<TransformComponent, SpriteComponent>();
		for (const ecs::Entity& entity : view)
		{
			if (!m_EntityWorld.HasComponent<Input::InputComponent>(entity))
				m_EntityWorld.AddComponent<Input::InputComponent>(entity);
		}
	}

	const auto view = registry.view<TransformComponent, SpriteComponent, Input::InputComponent>();
	for (const ecs::Entity& entity : view)
	{
		const auto& spriteComponent = view.get<SpriteComponent>(entity);
		auto& transformComponent = view.get<TransformComponent>(entity);
		auto& inputComponent = view.get<Input::InputComponent>(entity);
		vec2& pos = transformComponent.m_Position;

		if (inputComponent.IsKeyHeld(Input::EKeyboard::A))
			pos.x -= 1.f;
		if (inputComponent.IsKeyHeld(Input::EKeyboard::D))
			pos.x += 1.f;
		if (inputComponent.IsKeyHeld(Input::EKeyboard::W))
			pos.y += 1.f;
		if (inputComponent.IsKeyHeld(Input::EKeyboard::S))
			pos.y -= 1.f;
	}

	ImGui::EndFrame();
}

Saz::Application* Saz::CreateApplication()
{
	return new ::Application();
}
