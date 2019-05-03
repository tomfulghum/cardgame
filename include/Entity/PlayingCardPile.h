#pragma once

#include <vector>

#include "Entity.h"
#include "PlayingCard.h"
#include "Texture.h"

/*
	A pile of cards which can be clicked to draw a card.
*/

class PlayingCardPile : public Entity
{
	friend class EntityManager;

public:
	void Update() override;
	void Render() override;

	void SetDoHighlight(bool _doHighlight);

	PlayingCard* DrawCard();
	void AddToTop(PlayingCard* _card);
	int Count();

private:
	PlayingCardPile();

	std::vector<PlayingCard*> cards;
	Texture* texture;
	Texture* highlightTexture;
	bool highlight = false;
	bool doHighlight = true;

	void OnMouseOver() override;
};