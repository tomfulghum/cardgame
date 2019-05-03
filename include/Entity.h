#pragma once

#include <functional>

#include "glm.hpp"

/*
	Base class for all entities.
	Provides basic properties like position an scale as well as Update, Render, MouseOver and Click functions.
	All entities can only be constructed and are managed by the EntityManager.
*/
class Entity
{
	friend class EntityManager;

public:
	using OnClickCallback = std::function<void(Entity*)>;

	virtual void Update() = 0;
	virtual void Render() {}

	void SetActive(const bool _active);
	void SetRenderOrder(const int _renderOrder);
	void SetPosition(const int _x, const int _y);
	void SetPosition(const glm::vec2& _position);
	void SetDimensions(const glm::vec2& _dimensions);
	void SetScale(const float _scale);
	void SetOnClickCallback(OnClickCallback _callback);

	inline int GetRenderOrder() const { return this->renderOrder; }
	inline glm::vec2 GetPosition() const { return this->position; }
	inline glm::vec2 GetDimensions() const { return this->dimensions * this->scale; }
	inline float GetScale() const { return this->scale; }

protected:
	Entity(glm::vec2 _position = glm::vec2(), int _renderOrder = 0);

	bool active = false;
	int renderOrder = 0;
	glm::vec2 position = glm::vec2(0, 0);
	glm::vec2 dimensions = glm::vec2(1, 1);
	float scale = 1.0;

	OnClickCallback onClickCallback;

private:
	virtual void OnClick() {}
	void InvokeOnClick();

	virtual void OnMouseOver() {}
	void InvokeOnMouseOver();
};