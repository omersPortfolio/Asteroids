#include "SazPCH.h"
#include "Application.h"

#include "Saz/EntityWorld.h"
#include "Saz/GLFW/Window.h"
#include "Saz/InputSystem.h"
#include "Saz/RenderSystem.h"
#include "Saz/SFML/Window.h"
#include "Saz/SpriteComponent.h"
#include "Saz/TagComponent.h"
#include "Saz/TransformComponent.h"

#include <GLFW/glfw3.h>

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

		/*{
			glfwInit();
			Saz::WindowProps windowProps;
			windowProps.m_Title = "GLFW Window";
			windowProps.m_Size = ivec2(1280, 720);

			m_GLFWWindow = new Saz::glfw::Window(windowProps);
		}*/
		
		{
			Saz::WindowProps windowProps ;
			windowProps.m_Title = "SFML Window";
			windowProps.m_Size = ivec2(1280, 720);
			m_SFMLWindow = new sfml::Window(windowProps);
		}
	}

	Application::~Application()
	{
		delete m_SFMLWindow;
		//delete m_GLFWWindow;
		glfwTerminate();
	}

	void Application::Init()
	{
		//m_GLFWWindow->Init();
		m_SFMLWindow->Init();
		m_EntityWorld.Init();
	}

	void Application::Register()
	{
		m_EntityWorld.RegisterComponent<SpriteComponent>();
		m_EntityWorld.RegisterComponent<TagComponent>();
		m_EntityWorld.RegisterComponent<TransformComponent>();

		m_EntityWorld.RegisterSystem<ecs::RenderSystem>(*m_SFMLWindow);
		m_EntityWorld.RegisterSystem<ecs::InputSystem>(*m_SFMLWindow);
	}

	void Application::Destroy()
	{
		//m_GLFWWindow->Destroy();
		m_SFMLWindow->Destroy();
		m_EntityWorld.Destroy();
	}

	void Application::Update()
	{
		m_EntityWorld.Update();
	}

	void Application::Run(int argc, char* argv[])
	{
		Register();
		Init();

		while (m_Running)
		{
			/*m_GLFWWindow->Update();
			if (m_GLFWWindow->ShouldClose())
				break;*/

			m_SFMLWindow->Update();
			if (m_SFMLWindow->ShouldClose())
				break;

			Update();

			m_SFMLWindow->Render();
		}
	}
}