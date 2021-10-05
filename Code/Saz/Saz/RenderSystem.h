#pragma once

#include <Saz/System.h>

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

namespace ecs 
{
	class SAZ_API RenderSystem final : public System
	{
	public:
		
		RenderSystem(Saz::sfml::Window& sfmlWindow);
		~RenderSystem();

		virtual void Init() override;
		virtual void Update() override;

		void RenderSFML();

	private:
		Saz::sfml::Window& m_SFMLWindow;
	};
}
