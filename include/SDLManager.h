#pragma once

#include <string>

#include "SDL.h"

class SDLManager
{
public:
	static SDLManager* Instance();

	SDL_Window* GetWindow();
	SDL_Renderer* GetRenderer();
	bool ShouldQuit();

	void Initialize(const std::string& _windowName, const int _windowWidth, const int _windowHeight);
	void Terminate();
	void Update();
	void Render();

private:
	SDLManager();

	static SDLManager* instance;

	bool initialized = false;
	bool quit = false;
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;

	std::string GetInitializationErrorMessage();
};