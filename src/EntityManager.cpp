#include "EntityManager.h"

#include <algorithm>

#include "Toolbox.h"

EntityManager::EntityManager()
{

}

void EntityManager::Update()
{
	EntityManager* instance = Toolbox::GetEntityManager();

	for (auto entity : instance->entities)
	{
		entity->Update();
	}
}

void EntityManager::Render()
{
	EntityManager* instance = Toolbox::GetEntityManager();
	
	instance->SortEntitiesByRenderOrder();

	for (auto entity : instance->entities)
	{
		entity->Render();
	}
}

void EntityManager::AddEntity(Entity* _entity)
{
	EntityManager* instance = Toolbox::GetEntityManager();
	instance->entities.push_back(_entity);
}

void EntityManager::SortEntitiesByRenderOrder()
{
	std::sort(entities.begin(), entities.end(),
		[&](const Entity* a, const Entity* b) -> bool
		{
			return a->GetRenderOrder() > b->GetRenderOrder();
		}
	);
}