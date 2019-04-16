#include "PlayingCard.h"

#include <iostream>

#include "SDL.h"

#include "AssetDatabase.h"
#include "Environment.h"
#include "Time.h"

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

	

	Texture* textTest = AssetDatabase::RenderText("assets/fonts/uni0553-webfont.ttf", 48, std::to_string(Time::DeltaTime()));
	textTest->Render(glm::vec2(0, 0), 1);

	this->texture->Render(glm::vec2(0, 0), 1);
}