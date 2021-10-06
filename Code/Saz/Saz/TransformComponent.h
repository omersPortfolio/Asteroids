#pragma once

#include <Core/Vector.h>

namespace component
{
	struct TransformComponent
	{
		vec2 m_Position = vec2::Zero();
		vec2 m_Rotation = vec2::Zero();
		vec2 m_Scale = vec2::One();
	};
}
