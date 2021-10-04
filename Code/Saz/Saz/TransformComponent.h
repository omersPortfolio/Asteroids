#pragma once

#include <Core/Vector.h>

struct TransformComponent
{
	TransformComponent() = default;
	TransformComponent(const vec2& position)
	: m_Position(position) {}

	TransformComponent(const TransformComponent&) = default;

	vec2 m_Position;
};