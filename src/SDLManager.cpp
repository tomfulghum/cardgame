#include "SDLManager.h"

#include <iostream>

#include "Toolbox.h"

SDLManager::SDLManager()
{

}

inline std::string GetInitializationWarningMessage()
{
	return "[ERROR] SDLManager: SDLManager has not been initialized!";
}

SDL_Window* SDLManager::GetWindow()
{
	SDLManager* instance = Toolbox::GetSDLManager();

	if (!instance->initialized)
	{
		std::cout << GetInitializationWarningMessage() << std::endl;
		return nullptr;
	}
	else
	{
		return instance->window;
	}
}

SDL_Renderer* SDLManager::GetRenderer()
{
	SDLManager* instance = Toolbox::GetSDLManager();

	if (!instance->initialized)
	{
		std::cout << GetInitializationWarningMessage() << std::endl;
		return nullptr;
	}
	else
	{
		return instance->renderer;
	}
}

bool SDLManager::ShouldQuit()
{
	SDLManager* instance = Toolbox::GetSDLManager();

	return instance->quit;
}

void SDLManager::Initialize(const std::string& _windowName, const int _windowWidth, const int _windowHeight)
{
	SDLManager* instance = Toolbox::GetSDLManager();

	SDL_Init(SDL_INIT_EVERYTHING);

	instance->window = SDL_CreateWindow(_windowName.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, _windowWidth, _windowHeight, 0);
	if (instance->window == nullptr)
	{
		std::cout << "[ERROR] SDLManager: Failed to initialize SDL2 Window!" << std::endl;
		std::cout << SDL_GetError() << std::endl;
		return;
	}

	instance->renderer = SDL_CreateRenderer(instance->window, -1, SDL_RENDERER_ACCELERATED);
	if (instance->renderer == nullptr)
	{
		std::cout << "[ERROR] SDLManager: Failed to initialize SDL2 Renderer!" << std::endl;
		std::cout << SDL_GetError() << std::endl;
		return;
	}

	SDL_SetRenderDrawColor(instance->renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
	SDL_RenderClear(instance->renderer);

	instance->initialized = true;

	Toolbox::GetInputManager()->Update();
}

void SDLManager::Terminate()
{
	SDLManager* instance = Toolbox::GetSDLManager();

	SDL_DestroyWindow(instance->window);
	SDL_Quit();

	instance->initialized = false;
}

void SDLManager::Update()
{
	SDLManager* instance = Toolbox::GetSDLManager();
	InputManager* inputManager = Toolbox::GetInputManager();

	inputManager->Update();

	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			instance->quit = true;
			break;
		case SDL_MOUSEBUTTONDOWN:
		case SDL_MOUSEBUTTONUP:
			inputManager->HandleInputEvent(event);
			break;
		}
	}
}

void SDLManager::Render()
{
	SDLManager* instance = Toolbox::GetSDLManager();

	if (!instance->initialized)
	{
		std::cout << GetInitializationWarningMessage() << std::endl;
	}
	else
	{
		SDL_SetRenderDrawColor(instance->renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
		SDL_RenderClear(instance->renderer);

		// TODO: Render entities

		SDL_RenderPresent(instance->renderer);
	}
}