#include "Entity.h"

Entity::Entity(glm::vec2 _position, int _renderOrder) : position(_position), renderOrder(_renderOrder)
{

}

void Entity::SetActive(const bool _active)
{
	this->active = _active;
}

void Entity::SetRenderOrder(const int _renderOrder)
{
	this->renderOrder = _renderOrder;
}

void Entity::SetPosition(const int _x, const int _y)
{
	this->position = glm::vec2(_x, _y);
}

void Entity::SetPosition(const glm::vec2& _position)
{
	this->position = _position;
}

void Entity::SetDimensions(const glm::vec2& _dimensions)
{
	this->dimensions = _dimensions;
}

void Entity::SetScale(const float _scale)
{
	this->scale = _scale;
}

void Entity::SetOnClickCallback(OnClickCallback _callback)
{
	this->onClickCallback = _callback;
}

void Entity::InvokeOnClick()
{
	if (this->onClickCallback)
	{
		this->onClickCallback(this);
	}
	this->OnClick();
}

void Entity::InvokeOnMouseOver()
{
	this->OnMouseOver();
}