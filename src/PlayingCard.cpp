#include "PlayingCard.h"

#include <iostream>

#include "SDL.h"

#include "Environment.h"

PlayingCard::PlayingCard(Texture* _texture, glm::vec2 _position, int _renderOrder) : Entity(_position, _renderOrder), texture(_texture)
{

}

void PlayingCard::Update()
{

}

void PlayingCard::Render()
{
	//SDL_SetRenderDrawColor(Environment::GetRenderer(), 255, 255, 255, 255);
	//SDL_RenderDrawRect(Environment::GetRenderer(), &rect);

	SDL_Rect rect = SDL_Rect();
	rect.x = 0;
	rect.y = 0;
	rect.w = this->texture->GetWidth();
	rect.h = this->texture->GetHeight();

	SDL_RenderCopy(Environment::GetRenderer(), this->texture->GetTexture(), NULL, &rect);
}