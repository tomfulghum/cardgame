#pragma once

#include <functional>

#include "glm.hpp"

class Entity
{
	friend class EntityManager;

public:
	using OnClickCallback = std::function<void(Entity*)>;

	Entity(glm::vec2 _position = glm::vec2(), int _renderOrder = 0);

	virtual void Update() = 0;
	virtual void Render() {}

	void SetRenderOrder(const int _renderOrder);
	void SetPosition(const int _x, const int _y);
	void SetPosition(const glm::vec2& _position);
	void SetScale(const float _scale);
	void SetOnClickCallback(OnClickCallback _callback);

	inline int GetRenderOrder() const { return this->renderOrder; }
	inline glm::vec2 GetPosition() { return this->position; }
	inline glm::vec2 GetDimensions() { return this->dimensions * this->scale; }
	inline float GetScale() { return this->scale; }

protected:
	int renderOrder = 0;
	glm::vec2 position = glm::vec2(0, 0);
	glm::vec2 dimensions = glm::vec2(0, 0);
	float scale = 1.0;

	OnClickCallback onClickCallback;

private:
	virtual void OnClick() {}
	void InvokeOnClick();

	virtual void OnMouseOver() {}
	void InvokeOnMouseOver();
};