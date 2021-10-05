#pragma once

#include <Saz/EntityWorld.h>
#include <Saz/WindowBase.h>

namespace Saz
{
	namespace glfw
	{
		class Window;
	}

	namespace sfml
	{
		class Window;
	}
}

namespace Saz
{
	class Window;

	class SAZ_API Application
	{
	public:
		Application();
		~Application();

		void Run(int argc, char* argv[]);

		inline static Application& Get() { return *s_Instance; }

	protected:
		virtual void Init();
		virtual void Register();
		virtual void Destroy();
		virtual void Update();

		const ecs::EntityWorld& GetWorld();


	protected:
		Saz::sfml::Window* m_SFMLWindow = nullptr;

		ecs::EntityWorld m_EntityWorld;

		bool m_Running = true;

	private:
		static Application* s_Instance;
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}

