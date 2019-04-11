#include <iostream>

#include "SDLManager.h"

int main(int argc, char* args[])
{
	SDLManager* sdlManager = SDLManager::Instance();
	sdlManager->Initialize("Test", 640, 480);

	while (!sdlManager->ShouldQuit())
	{
		sdlManager->Update();
		sdlManager->Render();
	}

	sdlManager->Terminate();

	return 0;
}