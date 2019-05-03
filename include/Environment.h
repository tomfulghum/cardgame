#pragma once

#include <string>

#include "SDL.h"

class Environment
{
	friend class Toolbox;

public:
	static SDL_Window* GetWindow();
	static SDL_Renderer* GetRenderer();
	static int GetWindowWidth();
	static int GetWindowHeight();

	static void Initialize(const std::string& _windowName, const int _windowWidth, const int _windowHeight);
	static void Terminate();
	static void Run();
	static void Exit();

private:
	Environment();

	void Update();
	void Render();

	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;

	int windowWidth = 0;
	int windowHeight = 0;
	bool initialized = false;
	bool quit = false;
};