#pragma once

#include "SDL.h"

class Texture
{
public:
	Texture(SDL_Texture* _texture, int _width, int _height);

	SDL_Texture* GetTexture() { return this->texture; }
	int GetWidth() { return this->width; }
	int GetHeight() { return this->height; }

private:
	SDL_Texture* texture;
	int width;
	int height;
};