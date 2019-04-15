#pragma once

#include "Entity.h"

class PlayingCard : public Entity
{
public:
	PlayingCard();

	void Update() override;
	void Render() override;

private:
	int posX;
	int posY;
};