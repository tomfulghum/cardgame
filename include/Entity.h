#pragma once

#include "glm.hpp"

class Entity
{
public:
	Entity(glm::vec2 _position = glm::vec2(), int _renderOrder = 0);

	virtual void Update() = 0;
	virtual void Render() = 0;

	void SetRenderOrder(int _renderOrder);
	void SetPosition(int _x, int _y);

	inline int GetRenderOrder() const { return this->renderOrder; }
	inline glm::vec2 GetPosition() { return this->position; }

private:
	int renderOrder = 0;
	glm::vec2 position;
};