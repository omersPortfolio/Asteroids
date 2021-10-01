#include "FrameworkPCH.h"
#include "Application.h"


Application::Application()
{

}

Application::~Application()
{

}

void Application::Run()
{
	bool isRunning = Init();
	while (isRunning)
	{
		isRunning = Update();
		isRunning = Draw();
	}
	Destroy();
}

void Application::Quit()
{

}