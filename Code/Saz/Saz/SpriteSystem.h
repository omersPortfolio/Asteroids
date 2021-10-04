#pragma once
#include "System.h"

namespace Saz
{
	class Window;
}

namespace ecs 
{
	class World;

	class SAZ_API SpriteSystem final : public System
	{
	public:
		
		SpriteSystem(Saz::Window& window);
		~SpriteSystem();

		virtual void Init() override;
		virtual void Update() override;

	private:
		void OnPlayerComponentAdded(entt::registry& registry, entt::entity entity);

		Saz::Window& m_Window;
	};
}
