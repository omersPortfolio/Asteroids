#pragma once

#include <Saz/Window.h>

#include <glfw/glfw3.h>

namespace Saz
{
	// GLFW Window
	class SAZ_API WindowsWindow : public Saz::Window
	{
	public:
		WindowsWindow(const Saz::WindowProps& props);
		virtual ~WindowsWindow();

		void Update() override;

		inline unsigned int GetWidth() const { return m_Data.m_Width; }
		inline unsigned int GetHeight() const { return m_Data.m_Height; }

		inline void SetEventCallback(const EventCallbackFn& callback) override { m_Data.m_EventCallback = callback; }
		void SetVSync(bool enabled) override;
		bool IsVSync() const override;

		inline virtual void* GetNativeWindow() const { return m_Window; }

	private:
		virtual void Init(const Saz::WindowProps& props);
		virtual void Shutdown();

	private:
		GLFWwindow* m_Window;

		struct WindowData
		{
			String m_Title;
			int m_Width;
			int m_Height;
			bool m_VSync;

			EventCallbackFn m_EventCallback;
		};

		WindowData m_Data;
	};
}