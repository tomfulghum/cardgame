#include "Environment.h"

#include <iostream>

#include "SDL_ttf.h"

#include "AssetDatabase.h"
#include "Time.h"
#include "Toolbox.h"

Environment::Environment()
{

}

inline std::string GetInitializationWarningMessage()
{
	return "[ERROR] Environment: Environment has not been initialized!";
}

SDL_Window* Environment::GetWindow()
{
	Environment* instance = Toolbox::GetEnvironment();

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

SDL_Renderer* Environment::GetRenderer()
{
	Environment* instance = Toolbox::GetEnvironment();

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

int Environment::GetWindowWidth()
{
	Environment* instance = Toolbox::GetEnvironment();
	return instance->windowWidth;
}

int Environment::GetWindowHeight()
{
	Environment* instance = Toolbox::GetEnvironment();
	return instance->windowHeight;
}

void Environment::Initialize(const std::string& _windowName, const int _windowWidth, const int _windowHeight)
{
	Environment* instance = Toolbox::GetEnvironment();

	SDL_Init(SDL_INIT_EVERYTHING);

	instance->window = SDL_CreateWindow(_windowName.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, _windowWidth, _windowHeight, 0);
	if (instance->window == nullptr)
	{
		std::cout << "[ERROR] Environment: Failed to initialize SDL2 Window!" << std::endl;
		std::cout << SDL_GetError() << std::endl;
		return;
	}
	instance->windowWidth = _windowWidth;
	instance->windowHeight = _windowHeight;

	instance->renderer = SDL_CreateRenderer(instance->window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (instance->renderer == nullptr)
	{
		std::cout << "[ERROR] Environment: Failed to initialize SDL2 Renderer!" << std::endl;
		std::cout << SDL_GetError() << std::endl;
		return;
	}

	if (TTF_Init() == -1)
	{
		std::cout << "[ERROR] Environment: Failed to initialize SDL2_ttf!" << std::endl;
		std::cout << TTF_GetError() << std::endl;
		return;
	}

	SDL_SetRenderDrawColor(instance->renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
	SDL_RenderClear(instance->renderer);

	instance->initialized = true;

	Toolbox::GetInputManager()->Update();
}

void Environment::Terminate()
{
	Environment* instance = Toolbox::GetEnvironment();

	SDL_DestroyWindow(instance->window);
	SDL_Quit();

	instance->initialized = false;
}

void Environment::Run()
{
	Environment* instance = Toolbox::GetEnvironment();
	EntityManager* entityManager = Toolbox::GetEntityManager();

	Uint64 now = SDL_GetPerformanceCounter();
	Uint64 last = 0;

	while (!instance->quit)
	{
		now = SDL_GetPerformanceCounter();
		Time::deltaTime = (double)((now - last) * 1000 / (double)SDL_GetPerformanceFrequency()) * 0.001;
		last = now;

		instance->Update();
		entityManager->Update();
		instance->Render();
	}
}

void Environment::Exit()
{
	Environment* instance = Toolbox::GetEnvironment();
	instance->quit = true;
}

void Environment::Update()
{
	InputManager* inputManager = Toolbox::GetInputManager();

	inputManager->Update();

	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			this->quit = true;
			break;
		case SDL_MOUSEBUTTONDOWN:
		case SDL_MOUSEBUTTONUP:
			inputManager->HandleInputEvent(event);
			break;
		}
	}
}

void Environment::Render()
{
	if (!this->initialized)
	{
		std::cout << GetInitializationWarningMessage() << std::endl;
	}
	else
	{
		SDL_SetRenderDrawColor(this->renderer, 32, 32, 32, SDL_ALPHA_OPAQUE);
		SDL_RenderClear(this->renderer);

		Toolbox::GetEntityManager()->Render();

		SDL_RenderPresent(this->renderer);
	}
}