#pragma once
#include <glm/glm.hpp>
#include <vector>
#include <string>
#include <iostream>
#include "Mesh.h"

class Component
{
public:
    virtual ~Component() = default;
};

struct TransformComponent : public Component
{
    glm::vec3 position;
    glm::vec3 rotation;
    glm::vec3 scale;

    TransformComponent(const glm::vec3& pos = glm::vec3(0.0f),
        const glm::vec3& rot = glm::vec3(0.0f),
        const glm::vec3& scl = glm::vec3(1.0f))
        : position(pos), rotation(rot), scale(scl) {}
};

struct MeshComponent : public Component {
    std::vector<Vertex> vertices;
    std::vector<unsigned int> indices;
    const char* TexturePath;

    MeshComponent(const std::string& figure = "", const glm::vec3& color = glm::vec3(1,1,1), const char* texture = "");
};
