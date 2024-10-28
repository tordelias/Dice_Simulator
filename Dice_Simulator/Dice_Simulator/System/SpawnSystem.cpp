#include "SpawnSystem.h"
#include <iostream>
#include <string>

SpawnSystem::SpawnSystem(std::shared_ptr<EntityManager> entityManager)
{
}

SpawnSystem::~SpawnSystem()
{
}

void SpawnSystem::SpawnEntity()
{
}

void SpawnSystem::SpawnEntity(int x, int y, int z)
{
}

void SpawnSystem::SpawnEntity(int x, int y, int z, std::string texturePath)
{
}

void SpawnSystem::SpawnEntity(int x, int y, int z, std::string texturePath, std::string meshType)
{
}

void SpawnSystem::SpawnEntity(int x, int y, int z, std::string texturePath, std::string meshType, glm::vec3 scale)
{
}

void SpawnSystem::SpawnEntity(int x, int y, int z, std::string texturePath, std::string meshType, glm::vec3 scale, glm::vec3 rotation)
{
}

void SpawnSystem::SpawnEntity(int x, int y, int z, std::string texturePath, std::string meshType, glm::vec3 scale, glm::vec3 rotation, glm::vec3 position)
{
}
