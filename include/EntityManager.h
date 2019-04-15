#pragma once

#include <vector>

#include "Entity.h"

class EntityManager
{
	friend class Toolbox;

public:
	static void Update();
	static void Render();

	static void AddEntity(Entity* _entity);
	
private:
	EntityManager();

	std::vector<Entity*> entities;

	void SortEntitiesByRenderOrder();
};