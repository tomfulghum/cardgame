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
	std::vector<PlayingCard*>& DrawMultiple(const int _count);
	//void AddToTop(PlayingCard* _card);
	//void AddToBottom(PlayingCard* _card);
	//void AddRandomly(PlayingCard* _card);
	//PlayingCard* DrawTopCard();

private:
	std::vector<PlayingCard*> cards;
};