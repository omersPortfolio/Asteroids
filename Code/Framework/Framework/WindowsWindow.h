#pragma once

#include <Framework/Window.h>

#include <GLFW/glfw3.h>

namespace fw
{
	// GLFW Window
	class WindowsWindow : public fw::Window
	{
	public:
		WindowsWindow(const fw::WindowProps& props);
		virtual ~WindowsWindow();

		void Update() override;

		inline unsigned int GetWidth() const { return m_Data.m_Width; }
		inline unsigned int GetHeight() const { return m_Data.m_Height; }

		inline void SetEventCallback(const EventCallbackFn& callback) override { m_Data.m_EventCallback = callback; }
		void SetVSync(bool enabled) override;
		bool IsVSync() const override;

	private:
		virtual void Init(const fw::WindowProps& props);
		virtual void Shutdown();

	private:
		GLFWwindow* m_Window;

		struct WindowData
		{
			std::string m_Title;
			int m_Width;
			int m_Height;
			bool m_VSync;

			EventCallbackFn m_EventCallback;
		};

		WindowData m_Data;
	};
}