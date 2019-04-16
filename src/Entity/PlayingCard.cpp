#include "Entity/PlayingCard.h"

#include <iostream>

#include "SDL.h"

#include "AssetDatabase.h"
#include "Config.h"
#include "Environment.h"
#include "InputManager.h"
#include "Time.h"

PlayingCard::PlayingCard(PlayingCardType _type, glm::vec2 _position, int _renderOrder) : Entity(_position, _renderOrder), type(_type)
{
	switch (_type)
	{
	case PlayingCardType::ROCK:
		this->texture = AssetDatabase::GetTexture(SPRITE_CARD_ROCK_NAME);
		break;
	case PlayingCardType::PAPER:
		this->texture = AssetDatabase::GetTexture(SPRITE_CARD_PAPER_NAME);
		break;
	case PlayingCardType::SCISSORS:
		this->texture = AssetDatabase::GetTexture(SPRITE_CARD_SCISSORS_NAME);
		break;
	case PlayingCardType::LIZARD:
		this->texture = AssetDatabase::GetTexture(SPRITE_CARD_LIZARD_NAME);
		break;
	case PlayingCardType::SPOCK:
		this->texture = AssetDatabase::GetTexture(SPRITE_CARD_SPOCK_NAME);
		break;
	}

	this->dimensions = glm::vec2(this->texture->GetWidth(), this->texture->GetHeight());
	this->scale = 10.0;
}

void PlayingCard::Update()
{
	if (this->highlight && InputManager::GetMouseButtonDown(MouseButton::LEFT))
	{
		this->position.x += 10;
	}
}

void PlayingCard::Render()
{
	this->texture->Render(this->position, this->scale);

	if (this->highlight)
	{
		Texture* highlight = AssetDatabase::GetTexture(SPRITE_CARD_HIGHLIGHT_NAME);
		highlight->Render(this->position, this->scale);
		this->highlight = false;
	}
}

void PlayingCard::OnMouseOver()
{
	this->highlight = true;
}