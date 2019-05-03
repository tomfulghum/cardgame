#include "Texture.h"

#include "Environment.h"

Texture::Texture(SDL_Texture* _texture, int _width, int _height) : texture(_texture), width(_width), height(_height)
{

}

Texture::~Texture()
{
	SDL_DestroyTexture(this->texture);
}

/*
	Renders the texture at the given position with the given scale.
*/
void Texture::Render(const glm::vec2& _position, const double _scale)
{
	SDL_Rect rect = SDL_Rect();
	rect.x = (int)_position.x;
	rect.y = (int)_position.y;
	rect.w = (int)(this->width * _scale);
	rect.h = (int)(this->height * _scale);

	SDL_RenderCopy(Environment::GetRenderer(), this->texture, NULL, &rect);
}