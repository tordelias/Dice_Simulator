#pragma once
#include <vector>
#include <glm/glm.hpp>
class Mesh
{
	std::pair<std::vector<glm::vec3>, std::vector<glm::vec3>> CubeMesh();
	std::pair<std::vector<glm::vec3>, std::vector<glm::vec3>> SphereMesh();
	std::pair<std::vector<glm::vec3>, std::vector<glm::vec3>> CylinderMesh();
	std::pair<std::vector<glm::vec3>, std::vector<glm::vec3>> ConeMesh();
	std::pair<std::vector<glm::vec3>, std::vector<glm::vec3>> TorusMesh();
};

