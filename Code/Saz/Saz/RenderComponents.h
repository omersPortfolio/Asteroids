#pragma once

#include "glm/glm.hpp"

namespace Saz
{
	class FrameBuffer;
}


namespace component
{
	struct SpriteRendererComponent
	{
		glm::vec4 Color{ 1.0f, 1.0f, 1.0f, 1.0f };

		SpriteRendererComponent() = default;
		SpriteRendererComponent(const SpriteRendererComponent&) = default;
		SpriteRendererComponent(const glm::vec4& color)
			: Color(color) {}
	};

	struct FrameBufferComponent
	{
		Saz::Ref<Saz::FrameBuffer> FrameBuffer;
	};
}


