#include "Entity.h"

Entity::Entity(glm::vec2 _position, int _renderOrder) : position(_position), renderOrder(_renderOrder)
{

}

void Entity::Update()
{

}

void Entity::Render()
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