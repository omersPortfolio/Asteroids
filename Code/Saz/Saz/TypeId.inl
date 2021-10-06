#pragma once

#include <entt/entt.hpp>

template<typename Type>
constexpr Saz::TypeId Saz::ToTypeId()
{
	return entt::type_info<Type>::id();
}
