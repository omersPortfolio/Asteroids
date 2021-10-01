#pragma once

class Application
{
public:
	Application();
	virtual ~Application();

	void Run();
	void Quit();

protected:
	virtual bool Init() = 0;
	virtual void Destroy() = 0;

	virtual bool Update() = 0;
	virtual bool Draw() = 0;
};