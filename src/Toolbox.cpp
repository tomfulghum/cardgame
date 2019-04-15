#include "Toolbox.h"

#include <iostream>

EntityManager* Toolbox::entityManager;
SDLManager* Toolbox::sdlManager;
InputManager* Toolbox::inputManager;

Toolbox::Toolbox()
{

}

inline std::string GetInitializationWarningMessage()
{
	return "[WARNING] Toolbox: Toolbox has not been initialized!";
}

void Toolbox::Initialize()
{
	entityManager = new EntityManager();
	sdlManager = new SDLManager();
	inputManager = new InputManager();
}

void Toolbox::Terminate()
{
	delete(entityManager);
	delete(sdlManager);
	delete(inputManager);

	entityManager = nullptr;
	sdlManager = nullptr;
	inputManager = nullptr;
}

EntityManager* Toolbox::GetEntityManager()
{
	if (entityManager == nullptr)
	{
		std::cout << GetInitializationWarningMessage() << std::endl;
	}

	return entityManager;
}

SDLManager* Toolbox::GetSDLManager()
{
	if (sdlManager == nullptr)
	{
		std::cout << GetInitializationWarningMessage() << std::endl;
	}

	return sdlManager;
}


InputManager* Toolbox::GetInputManager()
{
	if (inputManager == nullptr)
	{
		std::cout << GetInitializationWarningMessage() << std::endl;
	}

	return inputManager;
}