#pragma once

#include "Events/Event.h"

namespace fw
{
	struct WindowProps
	{
		std::string m_Title;
		int m_Width;
		int m_Height;

		WindowProps(const std::string& title = "Framework",
					int width = 1280, int height = 720)
			: m_Title(title), m_Width(width), m_Height(height)

		{}
	};

	// Interface representing a desktop system based Window
	class Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() {}

		virtual void Update() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		static Window* Create(const WindowProps& props = WindowProps());
	};
}