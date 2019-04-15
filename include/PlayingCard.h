#pragma once

#include "glm.hpp"

#include "Entity.h"
#include "Texture.h"

class PlayingCard : public Entity
{
public:
	PlayingCard(Texture* _texture, glm::vec2 _position = glm::vec2(), int _renderOrder = 0);

	void Update() override;
	void Render() override;

private:
	Texture* texture;
};