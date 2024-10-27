#include "Component.h"
#include "Mesh.h"
#include <iostream>
#include <memory>

MeshComponent::MeshComponent(const std::string& figure, const glm::vec3& color, const std::string& texture)
    : TexturePath(texture)
{
    std::shared_ptr<Mesh> mesh = std::make_shared<Mesh>();

    if (figure == "Cube") {
        auto [cubeVertices, cubeIndices] = mesh->CubeMesh(color);
        vertices = cubeVertices;
        indices = cubeIndices;
    }
    else if (figure == "Sphere") {
        auto [sphereVertices, sphereIndices] = mesh->SphereMesh(color);
        vertices = sphereVertices;
        indices = sphereIndices;
    }
    else if (figure == "Cylinder") {
        auto [cylinderVertices, cylinderIndices] = mesh->CylinderMesh(color);
        vertices = cylinderVertices;
        indices = cylinderIndices;
    }
    else if (figure == "Cone") {
        auto [coneVertices, coneIndices] = mesh->ConeMesh(color);
        vertices = coneVertices;
        indices = coneIndices;
    }
    else if (figure == "Torus") {
        auto [torusVertices, torusIndices] = mesh->TorusMesh(color);
        vertices = torusVertices;
        indices = torusIndices;
    }
    else {
        std::cerr << "Invalid figure name" << std::endl;
    }
}
