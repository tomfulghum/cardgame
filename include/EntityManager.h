#pragma once

#include <map>

#include "Entity.h"

//        _.+._
//      (^\/^\/^)
//       \@*@*@/
//       {_____}
class EntityManager
{
public:
	EntityManager();
	~EntityManager();

	void Update();
	void Render();

	void AddEntity(Entity* _entity, int _order);
	
private:
	std::multimap<int, Entity*> entities;
};