#pragma once

#include <Framework/EntityWorld.h>
#include "Window.h"
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"

//namespace sf
//{
//	class RenderWindow;
//}

namespace fw
{
	class Window;

	class Application
	{
	public:
		Application();
		~Application();

		void Run(int argc, char* argv[]);

		void OnEvent(Event& e);

	protected:
		virtual void Init();
		virtual void Register();
		virtual void Destroy();
		virtual void Update(float deltaTime);

		const ecs::EntityWorld& GetWorld();

		bool OnWindowClosed(WindowCloseEvent& e);

	protected:
		std::unique_ptr<Window> m_Window;
		//sf::RenderWindow* m_SFMLWindow = nullptr;

		ecs::EntityWorld m_EntityWorld;

		bool m_Running = true;

	};

}

