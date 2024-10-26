#pragma once
#include <vector>
#include "../Entity.h"
#include <string>
class EntityManager
{
public:
	EntityManager();
	~EntityManager();
	void Update();
	void Render();
	void ClearData();
	bool HasNoEntities();
	//Entity& AddEntity(int EntityID);
	std::vector<Entity*> GetEntities() const;
	unsigned int GetEntityCount() { return EntityCount; };

private: 
	std::vector<Entity*> entities;
	int EntityCount; 
};

