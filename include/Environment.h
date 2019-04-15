#pragma once

#include <string>

#include "SDL.h"

class Environment
{
	friend class Toolbox;

public:
	static SDL_Window* GetWindow();
	static SDL_Renderer* GetRenderer();

	static void Initialize(const std::string& _windowName, const int _windowWidth, const int _windowHeight);
	static void Terminate();
	static void Run();

private:
	Environment();

	void Update();
	void Render();

	bool initialized = false;
	bool quit = false;
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
};