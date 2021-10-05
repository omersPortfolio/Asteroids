#pragma once

#include <Saz/Core.h>

namespace Saz
{
	struct WindowProps
	{
		String m_Title;
		ivec2 m_Size;

		WindowProps(const String& title = "Saz",
					ivec2 size = ivec2(1280, 720))
			: m_Title(title), m_Size(size)
		{}
	};

	// Interface representing a desktop system based Window
	class SAZ_API WindowBase
	{
	public:
		WindowBase() = delete;
		WindowBase(const WindowProps& props) {}
		virtual ~WindowBase() {}

		virtual void Init() {}
		virtual void Destroy() {}

		virtual void Update() = 0;

		virtual ivec2 GetSize() const = 0;

		virtual bool HasResized() const { return false; }
		virtual bool ShouldClose() const { return false; }

	private:
		WindowBase(const WindowBase&) = delete;
		WindowBase& operator=(const WindowBase&) = delete;
	};
}