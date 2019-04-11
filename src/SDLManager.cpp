#include "SDLManager.h"

#include <iostream>

SDLManager* SDLManager::instance;

SDLManager::SDLManager()
{

}

SDLManager* SDLManager::Instance()
{
	if (instance == nullptr)
	{
		instance = new SDLManager();
	}

	return instance;
}

SDL_Window* SDLManager::GetWindow()
{
	if (!this->initialized)
	{
		std::cout << GetInitializationErrorMessage() << std::endl;
		return nullptr;
	}
	else
	{
		return this->window;
	}
}

SDL_Renderer* SDLManager::GetRenderer()
{
	if (!this->initialized)
	{
		std::cout << GetInitializationErrorMessage() << std::endl;
		return nullptr;
	}
	else
	{
		return this->renderer;
	}
}

bool SDLManager::ShouldQuit()
{
	return this->quit;
}

void SDLManager::Initialize(const std::string& _windowName, const int _windowWidth, const int _windowHeight)
{
	SDL_Init(SDL_INIT_EVERYTHING);

	this->window = SDL_CreateWindow(_windowName.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, _windowWidth, _windowHeight, 0);
	if (window == nullptr)
	{
		std::cout << "[ERROR] SDLManager: Failed to initialize SDL2 Window!" << std::endl;
		std::cout << SDL_GetError() << std::endl;
		return;
	}

	this->renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == nullptr)
	{
		std::cout << "[ERROR] SDLManager: Failed to initialize SDL2 Renderer!" << std::endl;
		std::cout << SDL_GetError() << std::endl;
		return;
	}

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
	SDL_RenderClear(renderer);

	this->initialized = true;
}

void SDLManager::Terminate()
{
	SDL_DestroyWindow(this->window);
	SDL_Quit();

	this->initialized = false;
}

void SDLManager::Update()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		this->quit = event.type == SDL_QUIT;
	}
}

void SDLManager::Render()
{
	if (!this->initialized)
	{
		std::cout << GetInitializationErrorMessage() << std::endl;
	}
	else
	{
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
		SDL_RenderClear(renderer);

		// TODO: Render entities

		SDL_RenderPresent(renderer);
	}
}

std::string SDLManager::GetInitializationErrorMessage()
{
	return "[ERROR] SDLManager: SDLManager has not been initialized!";
}