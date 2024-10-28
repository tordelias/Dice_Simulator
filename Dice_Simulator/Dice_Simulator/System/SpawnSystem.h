#pragma once
#include "../Manager/EntityManager.h"
#include <string>
#include <GLFW/glfw3.h>
class GLFWwindow;
class SpawnSystem
{
public:
	SpawnSystem(std::shared_ptr<EntityManager> entityManager);
	~SpawnSystem();

	void input(GLFWwindow* window);


	void SpawnEntity();
	void SpawnEntity(int x, int y, int z);
	void SpawnEntity(int x, int y, int z, const char* texturePath);
	void SpawnEntity(int x, int y, int z, const char* texturePath, const char* meshType);
	void SpawnEntity(int x, int y, int z, const char* texturePath, const char* meshType, glm::vec3 scale);
	void SpawnEntity(int x, int y, int z, const char* texturePath, const char* meshType, glm::vec3 scale, glm::vec3 rotation);
	void SpawnEntity(int x, int y, int z, const char* texturePath, const char* meshType, glm::vec3 scale, glm::vec3 rotation, glm::vec3 position);

private:
	void deletelastEntity();
	std::shared_ptr<EntityManager> manager;
	int offset = 0;
	int offsetAmount = 2;
	bool spacePressedLastFrame = false;
	bool FPressedLastFrame = false;
};


