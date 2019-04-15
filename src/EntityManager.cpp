#include "EntityManager.h"

#include "Toolbox.h"

EntityManager::EntityManager()
{

}

void EntityManager::Update()
{
	EntityManager* instance = Toolbox::GetEntityManager();

	for (auto entity : instance->entities)
	{
		entity.second->Update();
	}
}

void EntityManager::Render()
{
	EntityManager* instance = Toolbox::GetEntityManager();

	for (auto entity : instance->entities)
	{
		entity.second->Render();
	}
}

void EntityManager::AddEntity(Entity* _entity, int _order)
{
	EntityManager* instance = Toolbox::GetEntityManager();

	instance->entities.insert(std::pair<int, Entity*>(_order, _entity));
}