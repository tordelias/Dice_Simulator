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
	void Render(const std::shared_ptr<Shader>& Shader, glm::mat4 viewproj, TransformComponent& pos);
	void ClearData();
	bool HasNoEntities();
	//Entity& AddEntity(int EntityID);
	std::vector<Entity*> GetEntities() const;
	unsigned int GetEntityCount() { return EntityCount; };

private: 
	std::vector<Entity*> entities;
	int EntityCount; 
};

