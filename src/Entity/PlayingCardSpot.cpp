#include "Entity/PlayingCardSpot.h"

#include "glm.hpp"

#include "AssetDatabase.h"
#include "Config.h"

PlayingCardSpot::PlayingCardSpot() : Entity(glm::vec2(), 0)
{
	this->highlightTexture = AssetDatabase::GetTexture(SPRITE_CARD_HIGHLIGHT_NAME);
	this->dimensions = glm::vec2(this->highlightTexture->GetWidth(), this->highlightTexture->GetHeight());
	this->scale = 10.0;
}

void PlayingCardSpot::Update()
{

}

void PlayingCardSpot::Render()
{
	if (this->card != nullptr)
	{
		this->card->GetTexture()->Render(this->position, this->scale);
	}

	if (this->doHighlight && this->highlight)
	{
		this->highlightTexture->Render(this->position, this->scale);
	}

	this->highlight = false;
}

void PlayingCardSpot::OnMouseOver()
{
	this->highlight = true;
}

void PlayingCardSpot::SetCard(PlayingCard* _card)
{
	if (_card != nullptr)
	{
		this->card = _card;
	}
}

void PlayingCardSpot::SetDoHighlight(bool _doHighlight)
{
	this->doHighlight = _doHighlight;
}

PlayingCard* PlayingCardSpot::TakeCard()
{
	PlayingCard* takenCard = this->card;
	this->card = nullptr;
	return takenCard;
}

PlayingCardType PlayingCardSpot::Peek()
{
	return this->card->GetType();
}

bool PlayingCardSpot::IsFree()
{
	return this->card == nullptr;
}

void PlayingCardSpot::Clear()
{
	delete(this->card);
	this->card = nullptr;
	this->doHighlight = false;
}

