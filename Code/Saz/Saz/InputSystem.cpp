#include "SazPCH.h"

#include "InputSystem.h"
#include "Saz/InputComponent.h"
#include "SFML/Window.h"

#include <entt/entt.hpp>

namespace ecs
{	
	InputSystem::InputSystem(Saz::sfml::Window& sfmlWindow)
		: m_SFMLWindow(sfmlWindow)
	{

	}

	InputSystem::~InputSystem()
	{

	}

	void InputSystem::Init()
	{

	}

	void InputSystem::Update()
	{
		auto& registry = m_World->m_Registry;

		m_KeyboardPrevious = std::move(m_KeyboardCurrent);
		m_MousePrevious = std::move(m_MouseCurrent);

		vec2 mouseDelta, mousePos;
		m_SFMLWindow.GatherKeyboard(m_KeyboardCurrent);
		m_SFMLWindow.GatherMouse(m_MouseCurrent, mouseDelta, mousePos);
		
		auto& view = registry.view<component::InputComponent>();
		for (const ecs::Entity& entity : view)
		{
			auto& component = view.get<component::InputComponent>(entity);
			component.m_KeyboardPrevious = m_KeyboardPrevious;
			component.m_KeyboardCurrent = m_KeyboardCurrent;
			component.m_MousePrevious = m_MousePrevious;
			component.m_MouseCurrent = m_MouseCurrent;
			component.m_MouseDelta = mouseDelta;
			component.m_MousePosition = mousePos;
		}
	}

}
