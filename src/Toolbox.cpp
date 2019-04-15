#include "Toolbox.h"

#include <iostream>

EntityManager* Toolbox::entityManager;
Environment* Toolbox::environment;
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
	environment = new Environment();
	inputManager = new InputManager();
}

void Toolbox::Terminate()
{
	delete(entityManager);
	delete(environment);
	delete(inputManager);

	entityManager = nullptr;
	environment = nullptr;
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

Environment* Toolbox::GetEnvironment()
{
	if (environment == nullptr)
	{
		std::cout << GetInitializationWarningMessage() << std::endl;
	}

	return environment;
}


InputManager* Toolbox::GetInputManager()
{
	if (inputManager == nullptr)
	{
		std::cout << GetInitializationWarningMessage() << std::endl;
	}

	return inputManager;
}