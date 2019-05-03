#pragma once

#include <vector>

#include "PlayingCard.h"

/*
	A deck of cards that can be drawn from.
*/
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