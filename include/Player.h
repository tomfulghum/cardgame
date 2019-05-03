#pragma once

#include <array>

#include "glm.hpp"

#include "Entity/PlayingCardSpot.h"
#include "Entity/GameController.h"

/*
	Represents one player.
*/

class Player
{
public:
	Player(GameController* _controller, glm::vec2 _position);

	void SetDoHighlight(bool _doHighlight);

	unsigned int GetScore() { return this->score; }

	bool GiveCard(PlayingCard* _card);
	void Score();
	void Reset();

private:
	GameController* controller;
	glm::vec2 position;
	std::array<PlayingCardSpot*, 5> hand;
	unsigned int score;

	void SpotOnClick(Entity* _spot);
};