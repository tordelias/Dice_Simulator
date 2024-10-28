#pragma once
#include "../Manager/EntityManager.h"
#include <string>
class SpawnSystem
{
public:
	SpawnSystem(std::shared_ptr<EntityManager> entityManager);
	~SpawnSystem();
	void SpawnEntity();
	void SpawnEntity(int x, int y, int z);
	void SpawnEntity(int x, int y, int z, std::string texturePath);
	void SpawnEntity(int x, int y, int z, std::string texturePath, std::string meshType);
	void SpawnEntity(int x, int y, int z, std::string texturePath, std::string meshType, glm::vec3 scale);
	void SpawnEntity(int x, int y, int z, std::string texturePath, std::string meshType, glm::vec3 scale, glm::vec3 rotation);
	void SpawnEntity(int x, int y, int z, std::string texturePath, std::string meshType, glm::vec3 scale, glm::vec3 rotation, glm::vec3 position);

private:
	std::shared_ptr<EntityManager> manager;
};


