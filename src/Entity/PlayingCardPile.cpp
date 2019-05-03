#include "Entity/PlayingCardPile.h"

#include "glm.hpp"

#include "AssetDatabase.h"
#include "Config.h"
#include "EntityManager.h"
#include "InputManager.h"

PlayingCardPile::PlayingCardPile() : Entity(glm::vec2(), 0)
{
	this->texture = AssetDatabase::GetTexture(SPRITE_CARD_DECK_NAME);
	this->highlightTexture = AssetDatabase::GetTexture(SPRITE_CARD_DECK_HIGHLIGHT_NAME);
	this->dimensions = glm::vec2(this->texture->GetWidth(), this->texture->GetHeight());
	this->scale = 10.0;
}

void PlayingCardPile::Update()
{

}

void PlayingCardPile::Render()
{
	this->texture->Render(this->position, this->scale);

	if (this->cards.size() > 0)
	{
		this->cards.back()->GetTexture()->Render(this->position, this->scale);
	}

	if (this->doHighlight && this->highlight && this->cards.size() > 0)
	{
		this->highlightTexture->Render(this->position, this->scale);
		this->highlight = false;
	}
}

void PlayingCardPile::OnMouseOver()
{
	this->highlight = true;
}

void PlayingCardPile::SetDoHighlight(bool _doHighlight)
{
	this->doHighlight = _doHighlight;
}

PlayingCard* PlayingCardPile::DrawCard()
{
	PlayingCard* card = nullptr;
	if (this->cards.size() > 0)
	{
		card = this->cards.back();
		this->cards.pop_back();
	}

	return card;
}

void PlayingCardPile::AddToTop(PlayingCard* _card)
{
	if (_card != nullptr)
	{
		this->cards.push_back(_card);
	}
}

void PlayingCardPile::AddToTop(std::vector<PlayingCard*>& _cards)
{
	if (_cards.size() > 0)
	{
		for (auto& card : _cards)
		{
			this->cards.push_back(card);
		}
	}
}

int PlayingCardPile::Count()
{
	return (int)this->cards.size();
}