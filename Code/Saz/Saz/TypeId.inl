#pragma once

#include <entt/entt.hpp>

template<typename Type>
constexpr core::TypeId core::ToTypeId()
{
	return entt::type_info<Type>::id();
}
