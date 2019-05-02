#include "PlayingCardDeck.h"

#include <algorithm>
#include <iostream>
#include <random>

#include "Config.h"

PlayingCardDeck::PlayingCardDeck()
{
	this->GenerateDeck();
}

void PlayingCardDeck::GenerateDeck()
{
	for (auto& card : cards)
	{
		delete(card);
	}
	this->cards.clear();

	this->cards.reserve(CARD_DECK_SIZE);

	for (int i = 0; i < CARD_ROCK_COUNT; i++)
	{
		this->cards.push_back(new PlayingCard(PlayingCardType::ROCK));
	}
	for (int i = 0; i < CARD_PAPER_COUNT; i++)
	{
		this->cards.push_back(new PlayingCard(PlayingCardType::PAPER));
	}
	for (int i = 0; i < CARD_SCISSORS_COUNT; i++)
	{
		this->cards.push_back(new PlayingCard(PlayingCardType::SCISSORS));
	}
	for (int i = 0; i < CARD_LIZARD_COUNT; i++)
	{
		this->cards.push_back(new PlayingCard(PlayingCardType::LIZARD));
	}
	for (int i = 0; i < CARD_SPOCK_COUNT; i++)
	{
		this->cards.push_back(new PlayingCard(PlayingCardType::SPOCK));
	}
}

void PlayingCardDeck::Shuffle()
{
	std::random_device rd;
	std::shuffle(this->cards.begin(), this->cards.end(), std::mt19937_64(rd()));
}

int PlayingCardDeck::Count()
{
	return this->cards.size();
}

PlayingCard* PlayingCardDeck::DrawCard()
{
	PlayingCard* card = nullptr;
	if (cards.size() > 0)
	{
		card = cards.back();
		this->cards.pop_back();
	}
	else
	{
		std::cout << "[WARNING] PlayingCardDeck: Card deck is empty!" << std::endl;
	}

	return card;
}

std::vector<PlayingCard*> PlayingCardDeck::DrawMultiple(const int _count)
{
	std::vector<PlayingCard*> drawnCards;
	for (int i = 0; i < _count; i++)
	{
		PlayingCard* card = DrawCard();
		if (card != nullptr)
		{
			drawnCards.push_back(card);
		}
	}

	return drawnCards;
}