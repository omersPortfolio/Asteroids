#include "SazPCH.h"
#include "Window.h"

#include <Core/Input.h>

#include <imgui-sfml/imgui-SFML.h>
#include <imgui/imgui.h>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>

namespace
{
	Input::EKeyboard ToKeyboard(sf::Keyboard::Key key)
	{
		switch (key)
		{
			// Alphabet
		case sf::Keyboard::Key::A: return Input::EKeyboard::A;
		case sf::Keyboard::Key::B: return Input::EKeyboard::B;
		case sf::Keyboard::Key::C: return Input::EKeyboard::C;
		case sf::Keyboard::Key::D: return Input::EKeyboard::D;
		case sf::Keyboard::Key::E: return Input::EKeyboard::E;
		case sf::Keyboard::Key::F: return Input::EKeyboard::F;
		case sf::Keyboard::Key::G: return Input::EKeyboard::G;
		case sf::Keyboard::Key::H: return Input::EKeyboard::H;
		case sf::Keyboard::Key::I: return Input::EKeyboard::I;
		case sf::Keyboard::Key::J: return Input::EKeyboard::J;
		case sf::Keyboard::Key::K: return Input::EKeyboard::K;
		case sf::Keyboard::Key::L: return Input::EKeyboard::L;
		case sf::Keyboard::Key::M: return Input::EKeyboard::M;
		case sf::Keyboard::Key::N: return Input::EKeyboard::N;
		case sf::Keyboard::Key::O: return Input::EKeyboard::O;
		case sf::Keyboard::Key::P: return Input::EKeyboard::P;
		case sf::Keyboard::Key::Q: return Input::EKeyboard::Q;
		case sf::Keyboard::Key::R: return Input::EKeyboard::R;
		case sf::Keyboard::Key::S: return Input::EKeyboard::S;
		case sf::Keyboard::Key::T: return Input::EKeyboard::T;
		case sf::Keyboard::Key::U: return Input::EKeyboard::U;
		case sf::Keyboard::Key::V: return Input::EKeyboard::V;
		case sf::Keyboard::Key::W: return Input::EKeyboard::W;
		case sf::Keyboard::Key::X: return Input::EKeyboard::X;
		case sf::Keyboard::Key::Y: return Input::EKeyboard::Y;
		case sf::Keyboard::Key::Z: return Input::EKeyboard::Z;

			// Numbers
		case sf::Keyboard::Key::Num0: return Input::EKeyboard::Num_0;
		case sf::Keyboard::Key::Num1: return Input::EKeyboard::Num_1;
		case sf::Keyboard::Key::Num2: return Input::EKeyboard::Num_2;
		case sf::Keyboard::Key::Num3: return Input::EKeyboard::Num_3;
		case sf::Keyboard::Key::Num4: return Input::EKeyboard::Num_4;
		case sf::Keyboard::Key::Num5: return Input::EKeyboard::Num_5;
		case sf::Keyboard::Key::Num6: return Input::EKeyboard::Num_6;
		case sf::Keyboard::Key::Num7: return Input::EKeyboard::Num_7;
		case sf::Keyboard::Key::Num8: return Input::EKeyboard::Num_8;
		case sf::Keyboard::Key::Num9: return Input::EKeyboard::Num_9;

			// Function
		case sf::Keyboard::Key::F1:		return Input::EKeyboard::F1;
		case sf::Keyboard::Key::F2:		return Input::EKeyboard::F2;
		case sf::Keyboard::Key::F3:		return Input::EKeyboard::F3;
		case sf::Keyboard::Key::F4:		return Input::EKeyboard::F4;
		case sf::Keyboard::Key::F5:		return Input::EKeyboard::F5;
		case sf::Keyboard::Key::F6:		return Input::EKeyboard::F6;
		case sf::Keyboard::Key::F7:		return Input::EKeyboard::F7;
		case sf::Keyboard::Key::F8:		return Input::EKeyboard::F8;
		case sf::Keyboard::Key::F9:		return Input::EKeyboard::F9;
		case sf::Keyboard::Key::F10:	return Input::EKeyboard::F10;
		case sf::Keyboard::Key::F11:	return Input::EKeyboard::F11;
		case sf::Keyboard::Key::F12:	return Input::EKeyboard::F12;
		case sf::Keyboard::Key::F13:	return Input::EKeyboard::F13;
		case sf::Keyboard::Key::F14:	return Input::EKeyboard::F14;
		case sf::Keyboard::Key::F15:	return Input::EKeyboard::F15;

			// Number Pad
		case sf::Keyboard::Key::Numpad0:	return Input::EKeyboard::Numpad_0;
		case sf::Keyboard::Key::Numpad1:	return Input::EKeyboard::Numpad_1;
		case sf::Keyboard::Key::Numpad2:	return Input::EKeyboard::Numpad_2;
		case sf::Keyboard::Key::Numpad3:	return Input::EKeyboard::Numpad_3;
		case sf::Keyboard::Key::Numpad4:	return Input::EKeyboard::Numpad_4;
		case sf::Keyboard::Key::Numpad5:	return Input::EKeyboard::Numpad_5;
		case sf::Keyboard::Key::Numpad6:	return Input::EKeyboard::Numpad_6;
		case sf::Keyboard::Key::Numpad7:	return Input::EKeyboard::Numpad_7;
		case sf::Keyboard::Key::Numpad8:	return Input::EKeyboard::Numpad_8;
		case sf::Keyboard::Key::Numpad9:	return Input::EKeyboard::Numpad_9;
		case sf::Keyboard::Key::Add:		return Input::EKeyboard::Numpad_Add;
		case sf::Keyboard::Key::Subtract:	return Input::EKeyboard::Numpad_Subtract;
		case sf::Keyboard::Key::Multiply:	return Input::EKeyboard::Numpad_Multiply;
		case sf::Keyboard::Key::Divide:		return Input::EKeyboard::Numpad_Divide;

			// Modifiers
		case sf::Keyboard::Key::LAlt:		return Input::EKeyboard::Alt_L;
		case sf::Keyboard::Key::RAlt:		return Input::EKeyboard::Alt_R;
		case sf::Keyboard::Key::LControl:	return Input::EKeyboard::Control_L;
		case sf::Keyboard::Key::RControl:	return Input::EKeyboard::Control_R;
		case sf::Keyboard::Key::LShift:		return Input::EKeyboard::Shift_L;
		case sf::Keyboard::Key::RShift:		return Input::EKeyboard::Shift_R;

			// Arrows
		case sf::Keyboard::Key::Up:		return Input::EKeyboard::Up;
		case sf::Keyboard::Key::Down:	return Input::EKeyboard::Down;
		case sf::Keyboard::Key::Left:	return Input::EKeyboard::Left;
		case sf::Keyboard::Key::Right:	return Input::EKeyboard::Right;

			// Other
		case sf::Keyboard::Key::Backslash:	return Input::EKeyboard::Backslash;
		case sf::Keyboard::Key::Backspace:	return Input::EKeyboard::Backspace;
		case sf::Keyboard::Key::LBracket:	return Input::EKeyboard::Bracket_L;
		case sf::Keyboard::Key::RBracket:	return Input::EKeyboard::Bracket_R;
		case sf::Keyboard::Key::Comma:		return Input::EKeyboard::Comma;
		case sf::Keyboard::Key::Delete:		return Input::EKeyboard::Delete;
		case sf::Keyboard::Key::End:		return Input::EKeyboard::End;
		case sf::Keyboard::Key::Enter:		return Input::EKeyboard::Enter;
		case sf::Keyboard::Key::Equal:		return Input::EKeyboard::Equal;
		case sf::Keyboard::Key::Escape:		return Input::EKeyboard::Escape;
		case sf::Keyboard::Key::Home:		return Input::EKeyboard::Home;
		case sf::Keyboard::Key::Hyphen:		return Input::EKeyboard::Hyphen;
		case sf::Keyboard::Key::Insert:		return Input::EKeyboard::Insert;
		case sf::Keyboard::Key::PageDown:	return Input::EKeyboard::Page_Down;
		case sf::Keyboard::Key::PageUp:		return Input::EKeyboard::Page_Up;
		case sf::Keyboard::Key::Pause:		return Input::EKeyboard::Pause;
		case sf::Keyboard::Key::Period:		return Input::EKeyboard::Period;
		case sf::Keyboard::Key::Quote:		return Input::EKeyboard::Quote;
		case sf::Keyboard::Key::Semicolon:	return Input::EKeyboard::Semicolon;
		case sf::Keyboard::Key::Slash:		return Input::EKeyboard::Slash;
		case sf::Keyboard::Key::Space:		return Input::EKeyboard::Space;
		case sf::Keyboard::Key::Tab:		return Input::EKeyboard::Tab;
		case sf::Keyboard::Key::Tilde:		return Input::EKeyboard::Tilde;
		}

		return Input::EKeyboard::Unknown;
	}

	Input::EMouse ToMouse(sf::Mouse::Button key)
	{
		switch (key)
		{
		case sf::Mouse::Button::Left:		return Input::EMouse::Button_1;
		case sf::Mouse::Button::Right:		return Input::EMouse::Button_2;
		case sf::Mouse::Button::Middle:		return Input::EMouse::Button_3;
		case sf::Mouse::Button::XButton1:	return Input::EMouse::Button_4;
		case sf::Mouse::Button::XButton2:	return Input::EMouse::Button_5;
		}

		return Input::EMouse::Unknown;
	}
}

namespace Saz::sfml
{
	Window::Window(const Saz::WindowProps& props)
		: Saz::WindowBase(props)
	{
		m_Title = props.m_Title;
		m_Size = props.m_Size;

		sf::ContextSettings settings;
		settings.majorVersion = 0;
		settings.minorVersion = 1;

		const sf::Uint32 style = sf::Style::Default;
		const sf::VideoMode videoMode = sf::VideoMode(props.m_Size.x, props.m_Size.y);
		m_Window.create(videoMode, m_Title.c_str(), style, settings);

		m_Texture.create(props.m_Size.x, props.m_Size.y, settings);
	}

	Window::~Window()
	{
	}


	void Window::Init()
	{
		ImGui::SFML::Init(m_Window);

		ImGuiIO& io = ImGui::GetIO();
		io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
		io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;

		// style
		{
			auto& colors = ImGui::GetStyle().Colors;
			colors[ImGuiCol_WindowBg] = ImVec4{ 0.1f, 0.105f, 0.11f, 1.0f };

			// Headers
			colors[ImGuiCol_Header] = ImVec4{ 0.2f, 0.205f, 0.21f, 1.0f };
			colors[ImGuiCol_HeaderHovered] = ImVec4{ 0.3f, 0.305f, 0.31f, 1.0f };
			colors[ImGuiCol_HeaderActive] = ImVec4{ 0.15f, 0.1505f, 0.151f, 1.0f };

			// Buttons
			colors[ImGuiCol_Button] = ImVec4{ 0.2f, 0.205f, 0.21f, 1.0f };
			colors[ImGuiCol_ButtonHovered] = ImVec4{ 0.3f, 0.305f, 0.31f, 1.0f };
			colors[ImGuiCol_ButtonActive] = ImVec4{ 0.15f, 0.1505f, 0.151f, 1.0f };

			// Frame BG
			colors[ImGuiCol_FrameBg] = ImVec4{ 0.2f, 0.205f, 0.21f, 1.0f };
			colors[ImGuiCol_FrameBgHovered] = ImVec4{ 0.3f, 0.305f, 0.31f, 1.0f };
			colors[ImGuiCol_FrameBgActive] = ImVec4{ 0.15f, 0.1505f, 0.151f, 1.0f };

			// Tabs
			colors[ImGuiCol_Tab] = ImVec4{ 0.15f, 0.1505f, 0.151f, 1.0f };
			colors[ImGuiCol_TabHovered] = ImVec4{ 0.38f, 0.3805f, 0.381f, 1.0f };
			colors[ImGuiCol_TabActive] = ImVec4{ 0.28f, 0.2805f, 0.281f, 1.0f };
			colors[ImGuiCol_TabUnfocused] = ImVec4{ 0.15f, 0.1505f, 0.151f, 1.0f };
			colors[ImGuiCol_TabUnfocusedActive] = ImVec4{ 0.2f, 0.205f, 0.21f, 1.0f };

			// Title
			colors[ImGuiCol_TitleBg] = ImVec4{ 0.15f, 0.1505f, 0.151f, 1.0f };
			colors[ImGuiCol_TitleBgActive] = ImVec4{ 0.15f, 0.1505f, 0.151f, 1.0f };
			colors[ImGuiCol_TitleBgCollapsed] = ImVec4{ 0.15f, 0.1505f, 0.151f, 1.0f };
		}
	}

	void Window::Destroy()
	{
		ImGui::SFML::Shutdown();
	}

	void Window::Update()
	{
		m_Time = m_Clock.restart();

		sf::Event eventData;
		while (m_Window.pollEvent(eventData))
		{
			ImGui::SFML::ProcessEvent(eventData);

			switch (eventData.type)
			{
			case sf::Event::Closed:
				m_Window.close();
				break;
			};
		}

		const sf::Vector2i rawPos = sf::Mouse::getPosition(m_Window);

		vec2 mousePos;
		mousePos.x = static_cast<float>(rawPos.x);
		mousePos.y = static_cast<float>(rawPos.y);
		m_MouseDelta = m_MousePos - mousePos;
		m_MousePos = mousePos;

		ImGui::SFML::Update(m_Window, m_Time);
		
	}

	void Window::Render()
	{
		{
			const sf::Texture& texture = m_Texture.getTexture();
			const sf::Vector2f size = sf::Vector2f(texture.getSize());

			sf::Sprite sprite;
			sprite.setTexture(texture);
			m_Window.draw(sprite);
		}

		ImGui::SFML::Render(m_Window);
		m_Window.display();
		m_Texture.clear(sf::Color::Blue);
	}

	bool Window::ShouldClose() const
	{
		return !m_Window.isOpen();
	}

	void Window::GatherKeyboard(Set<Input::EKeyboard>& out_Keys) const
	{
		for (int32_t i = sf::Keyboard::Key::A; i < sf::Keyboard::Key::KeyCount; ++i)
		{
			const sf::Keyboard::Key key = static_cast<sf::Keyboard::Key>(i);
			if (sf::Keyboard::isKeyPressed(key))
				out_Keys.insert(ToKeyboard(key));
		}
	}

	void Window::GatherMouse(Set<Input::EMouse>& out_Keys, vec2& out_Delta, vec2& out_Position) const
	{
		for (int32_t i = sf::Mouse::Button::Left; i < sf::Mouse::Button::ButtonCount; ++i)
		{
			const sf::Mouse::Button key = static_cast<sf::Mouse::Button>(i);
			if (sf::Mouse::isButtonPressed(key))
				out_Keys.insert(ToMouse(key));
		}

		out_Delta = m_MouseDelta;
		out_Position = m_MousePos;
	}
}
