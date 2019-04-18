#pragma once

#include <vector>

#include "Entity/PlayingCard.h"

class PlayingCardDeck
{
public:
	PlayingCardDeck();

	void GenerateDeck();
	void Shuffle();
	PlayingCard* DrawCard();
	std::vector<PlayingCard*> DrawMultiple(const int _count);

private:
	std::vector<PlayingCard*> cards;
};