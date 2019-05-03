#pragma once

#include "Texture.h"

enum class PlayingCardType
{
	ROCK,
	PAPER,
	SCISSORS,
	LIZARD,
	SPOCK,
	PLAYING_CARD_TYPE_COUNT
};

class PlayingCard
{
public:
	PlayingCard(const PlayingCardType _type = PlayingCardType::ROCK);

	PlayingCardType GetType() { return this->type; }
	Texture* GetTexture() { return this->cardTexture; }

	static bool Beats(PlayingCardType _left, PlayingCardType _right);

private:
	PlayingCardType type;
	Texture* cardTexture;
};