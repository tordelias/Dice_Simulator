#pragma once
#include <glm/glm.hpp>
#include <vector>
#include <memory>
#include <iostream>
class Component
{
};
struct TransformComponent {
    glm::vec3 position;
    glm::vec3 rotation;
    glm::vec3 scale;

    TransformComponent(const glm::vec3& pos = glm::vec3(0.0f),
        const glm::vec3& rot = glm::vec3(0.0f),
        const glm::vec3& scl = glm::vec3(1.0f))
        : position(pos), rotation(rot), scale(scl) {}

};

struct MeshComponent {
	std::vector<glm::vec3> vertices;
	std::vector<unsigned int> indices;
	MeshComponent(const std::vector<glm::vec3>& verts = std::vector<glm::vec3>(),
		const std::vector<unsigned int>& inds = std::vector<unsigned int>())
		: vertices(verts), indices(inds) {}

    //needs to add a string for texture and a string for chosen mesh in mesh class
};

