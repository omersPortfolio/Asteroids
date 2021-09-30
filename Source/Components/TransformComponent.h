#pragma once

#include "Math/vec2.h"

namespace sf
{
	class Texture;
	class Sprite;
}

struct TransformComponent
{
	TransformComponent() = default;
	TransformComponent(const vec2& position)
	: m_Position(position) {}

	TransformComponent(const TransformComponent&) = default;

	vec2 m_Position;
};