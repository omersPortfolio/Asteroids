#pragma once

#include <Saz/EntityWorld.h>
#include <Saz/WindowBase.h>

namespace Saz
{
	class ResourceManager;

	namespace glfw
	{
		class Window;
	}

	namespace sfml
	{
		class Window;
	}
}

namespace imgui
{
	class Log;
}

namespace Saz
{
	class Window;

	class SAZ_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run(int argc, char* argv[]);

		inline static Application& Get() { return *s_Instance; }

	protected:
		virtual void Init();
		virtual void Register();
		virtual void Destroy();
		virtual void Update();

		const ecs::EntityWorld& GetWorld();
		Saz::ResourceManager* GetResourceManager() { return m_pResourceManager; }


	protected:
		Saz::sfml::Window* m_SFMLWindow = nullptr;
		Saz::ResourceManager* m_pResourceManager;

		ecs::EntityWorld m_EntityWorld;

		bool m_Running = true;

		imgui::Log* m_ImGuiLog = nullptr;

	private:
		static Application* s_Instance;
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}

