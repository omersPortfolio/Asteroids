#include "GamePCH.h"

#include "Application.h"
#include <Saz/TransformComponent.h>
#include <Saz/PlayerComponent.h>
#include <Saz/SpriteComponent.h>

class ExampleLayer : public Saz::Layer
{
public:
	ExampleLayer()
		:Layer("Example")

	{

	}

	void OnUpdate() override
	{
		/*HZ_INFO("ExampleLayer::Update");*/

		if (Saz::Input::IsKeyPressed(SAZ_KEY_TAB))
			SPD_TRACE("Tab key is pressed (poll)!");
	}

	virtual void OnImGuiRender() override
	{
		ImGui::Begin("Test");
		ImGui::Text("Hello world");
		ImGui::End();
	}

	void OnEvent(Saz::Event& event) override
	{
		if (event.GetEventType() == Saz::EventType::KeyPressed)
		{
			Saz::KeyPressedEvent& e = (Saz::KeyPressedEvent&)event;
			if (e.GetKeyCode() == SAZ_KEY_TAB)
				SPD_TRACE("Tab key is pressed! (event)!");
			SPD_TRACE("{0}", (char)e.GetKeyCode());
		}
	}
};

Application::Application()
{
	PushLayer(new ExampleLayer());
	PushOverlay(new Saz::ImGuiLayer());
}

Application::~Application()
{
	//delete m_Log;
}

void Application::Init()
{
	Saz::Application::Init();
	
	//m_Log = new imgui::Log();
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

Saz::Application* Saz::CreateApplication()
{
	return new ::Application();
}
