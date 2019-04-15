#pragma once

#include <map>

#include "Entity.h"

class EntityManager
{
	friend class Toolbox;

public:
	static void Update();
	static void Render();

	static void AddEntity(Entity* _entity, int _order);
	
private:
	EntityManager();

	std::multimap<int, Entity*> entities;
};