#pragma once

#include <vector>

#include "PlayingCard.h"

class PlayingCardDeck
{
public:
	PlayingCardDeck();

	void GenerateDeck();
	void Shuffle();
	int Count();
	PlayingCard* DrawCard();

private:
	std::vector<PlayingCard*> cards;
};