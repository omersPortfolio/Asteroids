#pragma once

#include <Saz/WindowBase.h>

#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

namespace Input
{
	enum class EKeyboard;
	enum class EMouse;
}

namespace sf
{
	class Time;
	class Clock;
}

namespace Saz::sfml
{
	class Window final : public Saz::WindowBase
	{

	public:
		explicit Window(const Saz::WindowProps& props);
		~Window() override;

		void Init() override;
		void Destroy() override;

		void Update() override;
		void Render();

		ivec2 GetSize() const override { return m_Size; }

		bool ShouldClose() const override;

		void GatherKeyboard(Set<Input::EKeyboard>& out_Keys) const;
		void GatherMouse(Set<Input::EMouse>& out_Keys, vec2& out_Delta, vec2& out_Position) const;

		sf::RenderTexture m_Texture = { };

	private:
		String m_Title = { };
		ivec2 m_Size = { };

		vec2 m_MousePos = vec2(0.0f);
		vec2 m_MouseDelta = vec2(0.0f);

		
		sf::RenderWindow m_Window = { };

		sf::Time m_Time;
		sf::Clock m_Clock;
	};
}