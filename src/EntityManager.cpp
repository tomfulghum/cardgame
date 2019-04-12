#include "EntityManager.h"

EntityManager::EntityManager()
{

}

EntityManager::~EntityManager()
{

}

void EntityManager::Update()
{

}

void EntityManager::Render()
{

}

void EntityManager::AddEntity(Entity* _entity, int _order)
{
	this->entities.insert(std::pair<int, Entity*>(_order, _entity));
}