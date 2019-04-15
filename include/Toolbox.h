#pragma once

#include "EntityManager.h"
#include "InputManager.h"
#include "Environment.h"

//     _.+._
//   (^\/^\/^)
//    \@*@*@/
//    {_____}
class Toolbox
{
public:
	static void Initialize();
	static void Terminate();

	static Environment* GetEnvironment();
	static EntityManager* GetEntityManager();
	static InputManager* GetInputManager();

private:
	Toolbox();

	static Environment* environment;
	static EntityManager* entityManager;
	static InputManager* inputManager;
};