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
	PlayingCard(const PlayingCardType _type, const glm::vec2& _position = glm::vec2(), const int _renderOrder = 0);

	PlayingCardType GetType() { return this->type; }

	void Update() override;
	void Render() override;

private:
	PlayingCardType type;
	Texture* cardTexture;
	Texture* highlightTexture;
	bool highlight = false;

	void OnClick() override;
	void OnMouseOver() override;
};