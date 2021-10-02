#include "GamePCH.h"

#include "Application.h"
#include <Framework/TransformComponent.h>
#include <Framework/PlayerComponent.h>
#include <Framework/SpriteComponent.h>
#include <SFML/Graphics/RenderWindow.hpp>


Application::Application()
{
	
}

Application::~Application()
{
	//delete m_Log;
}

void Application::Init()
{
	fw::Application::Init();
	
	//m_Log = new imgui::Log();
}

void Application::Destroy()
{
	fw::Application::Destroy();
}
 
void Application::Register()
{
	fw::Application::Register();
}

void Application::Update(float deltaTime)
{
	fw::Application::Update(deltaTime);

	//imgui::Log::Update();

	/*if (ImGui::Button("Create Entity"))
	{
		auto player = m_EntityWorld.CreateEntity();
		TransformComponent& transformComp = m_EntityWorld.AddComponent<TransformComponent>(player);
		transformComp.m_Position = vec2(Math::RandomFloatInRange(50.0f, 1200.0f), Math::RandomFloatInRange(50.0f, 600.0f));;
		m_EntityWorld.AddComponent<PlayerComponent>(player);
		m_EntityWorld.AddComponent<SpriteComponent>(player);
	}*/
}
