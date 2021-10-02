#pragma once

#include <Framework/EntityWorld.h>

namespace ecs
{
	class System
	{
		friend class ecs::EntityWorld;

	public:
		virtual ~System() {}

		virtual void Init() {}
		virtual void Destroy() {}

		virtual void Update(float deltaTime) {};

	protected:
		ecs::EntityWorld* m_pWorld = nullptr;
	};
}
