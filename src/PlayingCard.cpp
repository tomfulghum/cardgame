#include "PlayingCard.h"

#include <iostream>

#include "SDL.h"
#include "Environment.h"

PlayingCard::PlayingCard() : Entity(), posX(100), posY(100)
{

}

void PlayingCard::Update()
{
	posX++;
	posY++;
}

void PlayingCard::Render()
{
	SDL_Rect rect = SDL_Rect();
	rect.w = 100;
	rect.h = 100;
	rect.x = this->posX;
	rect.y = this->posY;

	SDL_SetRenderDrawColor(Environment::GetRenderer(), 255, 255, 255, 255);
	SDL_RenderDrawRect(Environment::GetRenderer(), &rect);
}