#pragma once

#include <Saz/EntityWorld.h>

namespace ecs
{
	class SAZ_API System
	{
		friend class ecs::EntityWorld;

	public:
		virtual ~System() {}

		virtual void Init() {}
		virtual void Destroy() {}

		virtual void Update() {};

	protected:
		ecs::EntityWorld* m_pWorld = nullptr;
	};
}
