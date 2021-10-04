#include "GamePCH.h"

#include "Application.h"

int main(int agrc, char* argv[])
{
	auto app = Saz::CreateApplication();
	app->Run(agrc, argv);

	delete app;

	return EXIT_SUCCESS;
}