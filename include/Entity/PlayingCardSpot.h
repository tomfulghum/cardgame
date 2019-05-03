#pragma once

#include "Entity.h"
#include "PlayingCard.h"
#include "Texture.h"

class PlayingCardSpot : public Entity
{
	friend class EntityManager;

public:
	void Update() override;
	void Render() override;

	void SetCard(PlayingCard* _card);
	void SetDoHighlight(bool _doHighlight);

	PlayingCard* TakeCard();
	PlayingCardType Peek();
	bool IsFree();
	void Clear();

private:
	PlayingCardSpot();

	PlayingCard* card;
	Texture* highlightTexture;
	bool doHighlight = true;
	bool highlight = false;

	void OnMouseOver() override;
};