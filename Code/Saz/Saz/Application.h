#pragma once

#include <Saz/EntityWorld.h>
#include "Window.h"
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"
#include "LayerStack.h"

namespace Saz
{
	class Window;

	class SAZ_API Application
	{
	public:
		Application();
		~Application();

		void Run(int argc, char* argv[]);

		void OnEvent(Event& e);

		inline static Application& Get() { return *s_Instance; }

		inline Window& GetWindow() { return *m_Window; }

	protected:
		virtual void Init();
		virtual void Register();
		virtual void Destroy();
		virtual void Update();

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		const ecs::EntityWorld& GetWorld();

		bool OnWindowClosed(WindowCloseEvent& e);


	protected:
		std::unique_ptr<Window> m_Window;
		LayerStack m_LayerStack;

		ecs::EntityWorld m_EntityWorld;

		bool m_Running = true;

	private:
		static Application* s_Instance;
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}

