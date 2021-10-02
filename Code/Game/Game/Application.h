#pragma once

#include <Framework/Application.h>

namespace imgui
{
	class Log;
}

class Application final : public fw::Application
{
public:
	Application();
	virtual ~Application();

	virtual void Init() override;
	virtual void Destroy() override;
	virtual void Register() override;
	virtual void Update(float deltaTime) override;
	
private:
	imgui::Log* m_Log = nullptr;
};

