#pragma once
#include "System.h"

namespace sf
{
	class RenderWindow;
}

namespace ecs 
{
	class World;

	class SpriteSystem final : public System
	{
	public:
		
		SpriteSystem(sf::RenderWindow& window);
		~SpriteSystem();

		virtual void Init() override;
		virtual void Update(float deltaTime) override;

	private:
		void OnPlayerComponentAdded(entt::registry& registry, entt::entity entity);

		sf::RenderWindow& m_Window;
	};
}
