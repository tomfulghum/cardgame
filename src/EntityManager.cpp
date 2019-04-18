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

	for (auto& entity : instance->removedEntities)
	{
		auto it = std::find(instance->entities.begin(), instance->entities.end(), entity);
		instance->entities.erase(it);
	}
	instance->removedEntities.clear();

	for (auto& entity : instance->addedEntities)
	{
		instance->entities.push_back(entity);
	}
	instance->addedEntities.clear();

	instance->SortEntitiesByRenderOrder();

	glm::vec2 mousePosition = InputManager::GetMousePosition();
	auto rit = instance->entities.rbegin();
	for (; rit != instance->entities.rend(); ++rit)
	{
		if (IsPointInRectangle(mousePosition, (*rit)->position, (*rit)->GetDimensions()))
		{
			(*rit)->InvokeOnMouseOver();
			if (InputManager::GetMouseButtonDown(MouseButton::LEFT))
			{
				(*rit)->InvokeOnClick();
			}
			break;
		}
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

	if (std::find(instance->entities.begin(), instance->entities.end(), _entity) == instance->entities.end()
		&& std::find(instance->addedEntities.begin(), instance->addedEntities.end(), _entity) == instance->addedEntities.end())
	{
		instance->addedEntities.push_back(_entity);
	}
}

void EntityManager::RemoveEntity(Entity* _entity)
{
	EntityManager* instance = Toolbox::GetEntityManager();

	if (std::find(instance->entities.begin(), instance->entities.end(), _entity) != instance->entities.end())
	{
		instance->removedEntities.push_back(_entity);
	}
}

void EntityManager::SortEntitiesByRenderOrder()
{
	std::sort(entities.begin(), entities.end(), [&](const Entity* a, const Entity* b) -> bool {
		return a->renderOrder < b->renderOrder;
	});
}

bool EntityManager::IsPointInRectangle(const glm::vec2& _point, const glm::vec2& _position, const glm::vec2& _dimensions)
{
	return _point.x  >= _position.x 
		&& _point.y >= _position.y
		&& _point.x <= _position.x + _dimensions.x 
		&& _point.y <= _position.y + _dimensions.y;
}