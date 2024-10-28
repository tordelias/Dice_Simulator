#pragma once
#include <vector>
#include "../Entity.h"
#include <string>
#include <memory>
#include <glm/glm.hpp>
#include "../Resources/Shaders/shaderClass.h"
class Shader;
class Texture; 
class TransformComponent;
class EntityManager
{
public:
	EntityManager(std::shared_ptr<Shader> shader);
	~EntityManager();
	void Update();
	void Render(glm::mat4 viewproj);
	void ClearData();
	bool HasNoEntities();
	void AddEntity(std::shared_ptr<Entity>& entity);
	std::vector<Entity*> GetEntities() const;
	unsigned int GetEntityCount() { return EntityCount; };

private:
	void initalizeMesh(std::shared_ptr<Entity>& entity);
	void initalizeTexture(std::shared_ptr<Entity>& entity);
	std::vector<Entity*> entities;
	int EntityCount;
	std::vector<Texture> textures;
	std::shared_ptr<Shader> shader;	

};

