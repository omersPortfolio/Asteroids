#pragma once

#include <entt/entt.hpp>

namespace Saz
{
	using TypeId = entt::id_type;

	template<typename Type>
	constexpr Saz::TypeId ToTypeId();
}

#include "TypeId.inl"