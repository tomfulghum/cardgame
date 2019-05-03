#pragma once

#include <unordered_map>

#include "SDL.h"
#include "glm.hpp"

/*
	Manages the input state.
*/

enum class ButtonState
{
	NONE,
	PRESSED,
	UP,
	DOWN,
	BUTTON_STATE_COUNT
};

enum class MouseButton
{
	LEFT,
	MIDDLE,
	RIGHT,
	X1,
	X2,
	MOUSE_BUTTON_COUNT
};

class InputManager
{
	friend class Toolbox;
	friend class Environment;

public:
	static bool GetMouseButton(const MouseButton _button);
	static bool GetMouseButtonDown(const MouseButton _button);
	static bool GetMouseButtonUp(const MouseButton _button);
	static glm::vec2 GetMousePosition();

private:
	InputManager();

	std::unordered_map<MouseButton, ButtonState> mouseButtonStates;
	glm::vec2 cursorPosition;

	void Update();
	void HandleInputEvent(SDL_Event& _event);

	MouseButton GetMouseButtonFromSDL(Uint8 _button);
};