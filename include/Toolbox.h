#pragma once

#include "EntityManager.h"
#include "InputManager.h"
#include "SDLManager.h"


//     _.+._
//   (^\/^\/^)
//    \@*@*@/
//    {_____}
class Toolbox
{
public:
	static void Initialize();
	static void Terminate();

	static SDLManager* GetSDLManager();
	static EntityManager* GetEntityManager();
	static InputManager* GetInputManager();

private:
	Toolbox();

	static SDLManager* sdlManager;
	static EntityManager* entityManager;
	static InputManager* inputManager;
};