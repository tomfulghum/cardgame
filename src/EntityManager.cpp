#include "EntityManager.h"

#include <algorithm>

#include "Toolbox.h"
#include "InputManager.h"

EntityManager::EntityManager()
{

}

void EntityManager::Update()
{
	EntityManager* instance = Toolbox::GetEntityManager();

	instance->SortEntitiesByRenderOrder();

	std::vector<Entity*> mouseoverEntities;
	glm::vec2 mousePosition = InputManager::GetMousePosition();

	for (auto& entity : instance->entities)
	{
		if (IsPointInRectangle(mousePosition, entity->GetPosition(), entity->GetDimensions()))
		{
			mouseoverEntities.push_back(entity);
		}
	}

	if (mouseoverEntities.size() > 0)
	{
		mouseoverEntities.back()->OnMouseOver();
	}

	for (auto& entity : instance->entities)
	{
		entity->Update();
	}
}

void EntityManager::Render()
{
	EntityManager* instance = Toolbox::GetEntityManager();

	for (auto& entity : instance->entities)
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
			return a->GetRenderOrder() < b->GetRenderOrder();
		}
	);
}

bool EntityManager::IsPointInRectangle(const glm::vec2& _point, const glm::vec2& _position, const glm::vec2& _dimensions)
{
	return _point.x  >= _position.x 
		&& _point.y >= _position.y
		&& _point.x <= _position.x + _dimensions.x 
		&& _point.y <= _position.y + _dimensions.y;
}