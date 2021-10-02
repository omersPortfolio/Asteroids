#include "FrameworkPCH.h"

#include "Application.h"

#include <SFML/System.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "EntityWorld.h"
#include "SpriteComponent.h"
#include <imgui-sfml/imgui-SFML.h>
#include "TagComponent.h"
#include "PlayerComponent.h"
#include "TransformComponent.h"
#include "SpriteSystem.h"
#include <GLFW/glfw3.h>
#include "Events/ApplicationEvent.h"

namespace fw
{
#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	const ecs::EntityWorld& Application::GetWorld()
	{
		return m_EntityWorld;
	}

	Application::Application()
	{
		spd::Log::Init();

		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClosed));

		SPD_CORE_TRACE("{0}", e);
	}

	Application::~Application()
	{
		delete m_SFMLWindow;
	}

	void Application::Init()
	{
		m_EntityWorld.Init();
	}

	void Application::Register()
	{
		m_EntityWorld.RegisterComponent<SpriteComponent>();
		m_EntityWorld.RegisterComponent<TagComponent>();
		m_EntityWorld.RegisterComponent<PlayerComponent>();
		m_EntityWorld.RegisterComponent<TransformComponent>();

		m_EntityWorld.RegisterSystem<ecs::SpriteSystem>(*m_SFMLWindow);
	}

	void Application::Destroy()
	{
		m_EntityWorld.Destroy();
	}

	void Application::Update(float deltaTime)
	{
		m_EntityWorld.Update(deltaTime);
	}

	void Application::Run(int argc, char* argv[])
	{
		Register();
		Init();

		while (m_Running)
		{
			glClearColor(1, 0.5f, 0.5f, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->Update();
		}
	}

	bool Application::OnWindowClosed(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}
}