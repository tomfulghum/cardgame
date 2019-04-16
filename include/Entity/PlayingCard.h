#pragma once

#include "glm.hpp"

#include "Entity.h"
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

class PlayingCard : public Entity
{
public:
	PlayingCard(PlayingCardType _type, glm::vec2 _position = glm::vec2(), int _renderOrder = 0);

	PlayingCardType GetType() { return this->type; }

	void Update() override;
	void Render() override;
	void OnMouseOver() override;

private:
	PlayingCardType type;
	Texture* texture;

	bool highlight = false;
};