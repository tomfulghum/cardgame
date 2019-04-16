#pragma once

#include "glm.hpp"

class Entity
{
public:
	Entity(glm::vec2 _position = glm::vec2(), int _renderOrder = 0);

	virtual void Update() = 0;
	virtual void Render();
	virtual void OnMouseOver();

	void SetRenderOrder(const int _renderOrder);
	void SetPosition(const int _x, const int _y);
	void SetScale(const float _scale);

	inline int GetRenderOrder() const { return this->renderOrder; }
	inline glm::vec2 GetPosition() { return this->position; }
	inline glm::vec2 GetDimensions() { return this->dimensions * this->scale; }
	inline float GetScale() { return this->scale; }

protected:
	glm::vec2 position = glm::vec2(0, 0);
	glm::vec2 dimensions = glm::vec2(0, 0);
	float scale = 1.0;

private:
	int renderOrder = 0;
};