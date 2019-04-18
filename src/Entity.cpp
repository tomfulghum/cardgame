#include "Entity.h"

Entity::Entity(glm::vec2 _position, int _renderOrder) : position(_position), renderOrder(_renderOrder)
{

}

void Entity::SetRenderOrder(int _renderOrder)
{
	this->renderOrder = _renderOrder;
}

void Entity::SetPosition(int _x, int _y)
{
	this->position = glm::vec2(_x, _y);
}

void Entity::SetPosition(const glm::vec2& _position)
{
	this->position = _position;
}

void Entity::SetScale(float _scale)
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