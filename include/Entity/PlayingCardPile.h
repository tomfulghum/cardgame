#pragma once

#include <vector>

#include "Entity.h"
#include "PlayingCard.h"
#include "Texture.h"

class PlayingCardPile : public Entity
{
public:
	PlayingCardPile(const glm::vec2& _position, const int _renderOrder);

	void Update() override;
	void Render() override;

	PlayingCard* DrawCard();
	void AddToTop(PlayingCard* _card);
	void AddToTop(std::vector<PlayingCard*>& _cards);
	int Count();

private:
	std::vector<PlayingCard*> cards;
	Texture* texture;
	Texture* highlightTexture;
	bool highlight = false;

	void OnMouseOver() override;
};