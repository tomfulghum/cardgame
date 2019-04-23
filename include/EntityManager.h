#pragma once

#include <vector>

#include "Entity.h"

class EntityManager
{
	friend class Toolbox;

public:
	static void Update();
	static void Render();

	template<class T> static T* CreateEntity();

	static void DestroyEntity(Entity* _entity);
	
private:
	EntityManager();

	std::vector<Entity*> entities;
	std::vector<Entity*> addedEntities;
	std::vector<Entity*> destroyedEntities;

	void SortEntitiesByRenderOrder();

	static bool IsPointInRectangle(const glm::vec2& _point, const glm::vec2& _position, const glm::vec2& _dimensions);
};

template<class T>
T* EntityManager::CreateEntity()
{
	EntityManager* instance = Toolbox::GetEntityManager();

	Entity* entity = new T();
	entity->SetActive(true);
	instance->addedEntities.push_back(entity);

	return static_cast<T*>(entity);
}