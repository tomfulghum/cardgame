#pragma once

#include "glm.hpp"
#include "SDL.h"

class Texture
{
public:
	Texture(SDL_Texture* _texture, int _width, int _height);
	~Texture();

	SDL_Texture* GetTexture() { return this->texture; }
	int GetWidth() { return this->width; }
	int GetHeight() { return this->height; }

	void Render(const glm::vec2& _position, const double _scale);

private:
	SDL_Texture* texture;
	int width;
	int height;
};