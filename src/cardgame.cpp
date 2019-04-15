#include <iostream>

#include "Toolbox.h"

int main(int argc, char* args[])
{
	Toolbox::Initialize();
	SDLManager::Initialize("Test", 640, 480);

	while (!SDLManager::ShouldQuit())
	{
		SDLManager::Update();
		SDLManager::Render();
	}

	SDLManager::Terminate();
	Toolbox::Terminate();

	return 0;
}