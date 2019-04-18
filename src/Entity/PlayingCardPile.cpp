#include "Entity/PlayingCardPile.h"

#include "AssetDatabase.h"
#include "EntityManager.h"
#include "InputManager.h"
#include "Config.h"

PlayingCardPile::PlayingCardPile(const glm::vec2& _position, const int _renderOrder) : Entity(_position, _renderOrder)
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

	if (this->highlight)
	{
		this->highlightTexture->Render(this->position, this->scale);
		this->highlight = false;
	}
}

void PlayingCardPile::OnMouseOver()
{
	this->highlight = true;
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
		if (this->cards.size() > 0)
		{
			EntityManager::RemoveEntity(this->cards.back());
			this->cards.back()->SetOnClickCallback(nullptr);
		}

		_card->SetPosition(this->position);
		_card->SetRenderOrder(this->renderOrder + 1);
		EntityManager::AddEntity(_card);

		this->cards.push_back(_card);
	}
}

void PlayingCardPile::AddToTop(std::vector<PlayingCard*>& _cards)
{
	if (_cards.size() > 0)
	{
		if (this->cards.size() > 0)
		{
			EntityManager::RemoveEntity(this->cards.back());
			this->cards.back()->SetOnClickCallback(nullptr);
		}

		for (auto& card : _cards)
		{
			this->cards.push_back(card);
		}

		this->cards.back()->SetPosition(this->position);
		this->cards.back()->SetRenderOrder(this->renderOrder + 1);
		EntityManager::AddEntity(this->cards.back());
	}
}

int PlayingCardPile::Count()
{
	return this->cards.size();
}