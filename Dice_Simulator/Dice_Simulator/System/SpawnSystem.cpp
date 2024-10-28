#include "SpawnSystem.h"
#include <iostream>
#include <string>
#include "../Entity.h"
#include "../Component/Component.h"
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>
#include <memory>


SpawnSystem::SpawnSystem(std::shared_ptr<EntityManager> entityManager) : manager(entityManager)
{
}

SpawnSystem::~SpawnSystem()
{
}

void SpawnSystem::input(GLFWwindow* window)
{
	bool isQPressed = glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS;
	if (isQPressed && !spacePressedLastFrame)
	{
		 SpawnEntity(offset, 0, -5);
	}
	spacePressedLastFrame = isQPressed;

	bool isFPressed = glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS;
	if (isFPressed && !FPressedLastFrame)
	{
		deletelastEntity();

	}
	FPressedLastFrame = isFPressed;
}

void SpawnSystem::SpawnEntity()
{
	std::shared_ptr<Entity> cube = std::make_shared<Entity>();
	cube->AddComponent<TransformComponent>(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f));
	cube->AddComponent<MeshComponent>("Cube", glm::vec3(1.0f, 1.0f, 1.0f), "");
	manager->AddEntity(cube);
	offset += offsetAmount;

}

void SpawnSystem::SpawnEntity(int x, int y, int z)
{
	std::shared_ptr<Entity> cube = std::make_shared<Entity>();
	cube->AddComponent<TransformComponent>(glm::vec3(x, y, z), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f));
	cube->AddComponent<MeshComponent>("Cube", glm::vec3(1.0f, 1.0f, 1.0f), "");
	manager->AddEntity(cube);
	offset += offsetAmount;
}

void SpawnSystem::SpawnEntity(int x, int y, int z, const char* texturePath)
{
	std::shared_ptr<Entity> cube = std::make_shared<Entity>();
	cube->AddComponent<TransformComponent>(glm::vec3(x, y, z), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f));
	cube->AddComponent<MeshComponent>("Cube", glm::vec3(1.0f, 1.0f, 1.0f), texturePath);
	manager->AddEntity(cube);
	offset += offsetAmount;
}

void SpawnSystem::SpawnEntity(int x, int y, int z, const char* texturePath, const char* meshType)
{
	std::shared_ptr<Entity> cube = std::make_shared<Entity>();
	cube->AddComponent<TransformComponent>(glm::vec3(x, y, z), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f));
	cube->AddComponent<MeshComponent>(meshType, glm::vec3(1.0f, 1.0f, 1.0f), texturePath);
	manager->AddEntity(cube);
	offset += offsetAmount;
}

void SpawnSystem::SpawnEntity(int x, int y, int z, const char* texturePath, const char* meshType, glm::vec3 scale)
{
	std::shared_ptr<Entity> cube = std::make_shared<Entity>();
	cube->AddComponent<TransformComponent>(glm::vec3(x, y, z), glm::vec3(0.0f, 0.0f, 0.0f), scale);
	cube->AddComponent<MeshComponent>(meshType, scale, texturePath);
	manager->AddEntity(cube);
	offset += offsetAmount;
}

void SpawnSystem::SpawnEntity(int x, int y, int z, const char* texturePath, const char* meshType, glm::vec3 scale, glm::vec3 rotation)
{
	std::shared_ptr<Entity> cube = std::make_shared<Entity>();
	cube->AddComponent<TransformComponent>(glm::vec3(x, y, z), rotation, scale);
	cube->AddComponent<MeshComponent>(meshType, scale, texturePath);
	manager->AddEntity(cube);
	offset += offsetAmount;
}

void SpawnSystem::SpawnEntity(int x, int y, int z, const char* texturePath, const char* meshType, glm::vec3 scale, glm::vec3 rotation, glm::vec3 position)
{
	std::shared_ptr<Entity> cube = std::make_shared<Entity>();
	cube->AddComponent<TransformComponent>(position, rotation, scale);
	cube->AddComponent<MeshComponent>(meshType, scale, texturePath);
	manager->AddEntity(cube);
	offset += offsetAmount;
}

void SpawnSystem::deletelastEntity()
{
	manager->RemoveLastEntity();
	offset -= offsetAmount;
}
