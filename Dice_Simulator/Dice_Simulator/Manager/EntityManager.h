#pragma once
#include <vector>
#include "../Entity.h"
#include <string>
#include <memory>
#include <glm/glm.hpp>
class Shader; 
class TransformComponent;
class EntityManager
{
public:
	EntityManager();
	~EntityManager();
	void Update();
	void Render(const std::shared_ptr<Shader>& Shader, glm::mat4 viewproj);
	void ClearData();
	bool HasNoEntities();
	void AddEntity(Entity& entity);
	std::vector<Entity*> GetEntities() const;
	unsigned int GetEntityCount() { return EntityCount; };

private: 
	void initalizeMesh(Entity& entity);
	std::vector<Entity*> entities;
	int EntityCount; 
};

