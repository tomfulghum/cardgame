#pragma once

#include <vector>

#include "Entity.h"
#include "PlayingCard.h"
#include "Texture.h"

class PlayingCardPile : public Entity
{
	friend class EntityManager;

public:
	void Update() override;
	void Render() override;

	PlayingCard* DrawCard();
	void AddToTop(PlayingCard* _card);
	void AddToTop(std::vector<PlayingCard*>& _cards);
	int Count();

private:
	PlayingCardPile();

	std::vector<PlayingCard*> cards;
	Texture* texture;
	Texture* highlightTexture;
	bool highlight = false;

	void OnMouseOver() override;
};