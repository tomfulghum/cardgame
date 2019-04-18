#include "Entity/PlayingCard.h"

#include <iostream>

#include "SDL.h"

#include "AssetDatabase.h"
#include "Config.h"
#include "Environment.h"
#include "InputManager.h"
#include "Time.h"

PlayingCard::PlayingCard(const PlayingCardType _type, const glm::vec2& _position, const int _renderOrder) : Entity(_position, _renderOrder), type(_type)
{
	switch (_type)
	{
	case PlayingCardType::ROCK:
		this->cardTexture = AssetDatabase::GetTexture(SPRITE_CARD_ROCK_NAME);
		break;
	case PlayingCardType::PAPER:
		this->cardTexture = AssetDatabase::GetTexture(SPRITE_CARD_PAPER_NAME);
		break;
	case PlayingCardType::SCISSORS:
		this->cardTexture = AssetDatabase::GetTexture(SPRITE_CARD_SCISSORS_NAME);
		break;
	case PlayingCardType::LIZARD:
		this->cardTexture = AssetDatabase::GetTexture(SPRITE_CARD_LIZARD_NAME);
		break;
	case PlayingCardType::SPOCK:
		this->cardTexture = AssetDatabase::GetTexture(SPRITE_CARD_SPOCK_NAME);
		break;
	}

	this->highlightTexture = AssetDatabase::GetTexture(SPRITE_CARD_HIGHLIGHT_NAME);
	this->dimensions = glm::vec2(this->cardTexture->GetWidth(), this->cardTexture->GetHeight());
	this->scale = 10.0;
}

void PlayingCard::Update()
{

}

void PlayingCard::Render()
{
	this->cardTexture->Render(this->position, this->scale);

	if (this->highlight)
	{
		this->highlightTexture->Render(this->position, this->scale);
		this->highlight = false;
	}
}

void PlayingCard::OnMouseOver()
{
	this->highlight = true;
}

void PlayingCard::OnClick()
{
	this->position.x += 10;
}