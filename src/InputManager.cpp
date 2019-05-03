#include <iostream>

#include "InputManager.h"
#include "Toolbox.h"

InputManager::InputManager() : cursorPosition(glm::vec2(0, 0))
{
	for (int i = 0; i < (int)MouseButton::MOUSE_BUTTON_COUNT; i++)
	{
		mouseButtonStates.insert_or_assign((MouseButton)i, ButtonState::NONE);
	}
}

bool InputManager::GetMouseButton(const MouseButton _button)
{
	InputManager* instance = Toolbox::GetInputManager();
	return instance->mouseButtonStates[_button] == ButtonState::PRESSED || instance->mouseButtonStates[_button] == ButtonState::DOWN;
}

bool InputManager::GetMouseButtonDown(const MouseButton _button)
{
	InputManager* instance = Toolbox::GetInputManager();
	return instance->mouseButtonStates[_button] == ButtonState::DOWN;
}

bool InputManager::GetMouseButtonUp(const MouseButton _button)
{
	InputManager* instance = Toolbox::GetInputManager();
	return instance->mouseButtonStates[_button] == ButtonState::UP;
}

glm::vec2 InputManager::GetMousePosition()
{
	int x, y;
	SDL_GetMouseState(&x, &y);
	return glm::vec2(x, y);
}

/*
	Updates the button states.
	If a button was DOWN in the previous frame, it is now PRESSED.
	If a button was UP in the previous frame, it is now NONE.
*/
void InputManager::Update()
{
	for (auto& state : mouseButtonStates)
	{
		switch (state.second)
		{
		case(ButtonState::DOWN):
			state.second = ButtonState::PRESSED;
			break;
		case(ButtonState::UP):
			state.second = ButtonState::NONE;
			break;
		}
	}
}

/*
	Handles an SDL input event provided by Environment.
*/
void InputManager::HandleInputEvent(SDL_Event& _event)
{
	switch (_event.type)
	{
	case SDL_MOUSEBUTTONDOWN:
		mouseButtonStates.insert_or_assign(GetMouseButtonFromSDL(_event.button.button), ButtonState::DOWN);
		break;
	case SDL_MOUSEBUTTONUP:
		mouseButtonStates.insert_or_assign(GetMouseButtonFromSDL(_event.button.button), ButtonState::UP);
		break;
	default:
		std::cout << "[WARNING] InputManager: Invalid or unimplemented SDL Event: " << _event.type << std::endl;
	}
}

/*
	Translates from SDL mouse button to internal mouse button type.
*/
MouseButton InputManager::GetMouseButtonFromSDL(Uint8 _button)
{
	switch (_button)
	{
	case SDL_BUTTON_LEFT:
		return MouseButton::LEFT;
	case SDL_BUTTON_RIGHT:
		return MouseButton::RIGHT;
	case SDL_BUTTON_MIDDLE:
		return MouseButton::MIDDLE;
	case SDL_BUTTON_X1:
		return MouseButton::X1;
	case SDL_BUTTON_X2:
		return MouseButton::X2;
	default:
		return MouseButton::MOUSE_BUTTON_COUNT;
	}
}