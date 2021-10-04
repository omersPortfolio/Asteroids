#include "SazPCH.h"

#include "Application.h"

#include "EntityWorld.h"
#include "SpriteComponent.h"
#include "TagComponent.h"
#include "PlayerComponent.h"
#include "TransformComponent.h"
#include "SpriteSystem.h"
#include <glad/glad.h>
#include "Events/ApplicationEvent.h"
#include "Input.h"

namespace Saz
{
	Application* Application::s_Instance = nullptr;

	const ecs::EntityWorld& Application::GetWorld()
	{
		return m_EntityWorld;
	}

	Application::Application()
	{
		SAZ_ASSERT(!s_Instance, "Application already exists!");
		s_Instance = this;
		spd::Log::Init();

		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(SAZ_BIND_EVENT_FN(Application::OnEvent));
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(SAZ_BIND_EVENT_FN(Application::OnWindowClosed));

		//SPD_CORE_TRACE("{0}", e);

		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin(); )
		{
			(*--it)->OnEvent(e);
			if (e.Handled)
				break;
		}
	}

	Application::~Application()
	{
		//delete m_SFMLWindow;
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

		m_EntityWorld.RegisterSystem<ecs::SpriteSystem>(*m_Window);
	}

	void Application::Destroy()
	{
		m_EntityWorld.Destroy();
	}

	void Application::Update()
	{
		m_EntityWorld.Update();
	}

	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
		layer->OnAttach();
	}

	void Application::PushOverlay(Layer* layer)
	{
		m_LayerStack.PushOverlay(layer);
		layer->OnAttach();
	}

	void Application::Run(int argc, char* argv[])
	{
		Register();
		Init();

		while (m_Running)
		{
			glClearColor(1, 0.5f, 0.5f, 1);
			glClear(GL_COLOR_BUFFER_BIT);

			Update();

			for (Layer* layer : m_LayerStack)
				layer->OnUpdate();

			//auto [x, y] = Input::GetMousePosition();
			//SPD_CORE_TRACE("{0}, {1}", x, y);
			//Input::IsKeyPressed(GLFW_KEY_TAB);

			m_Window->Update();
		}
	}

	bool Application::OnWindowClosed(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}
}