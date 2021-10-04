#pragma once

#include <Saz/Application.h>

namespace imgui
{
	class Log;
}

class Application final : public Saz::Application
{
public:
	Application();
	virtual ~Application();

	virtual void Init() override;
	virtual void Destroy() override;
	virtual void Register() override;
	virtual void Update() override;
	
private:
	//imgui::Log* m_Log = nullptr;
};

