#pragma once
#define GLM_ENABLE_EXPERIMENTAL
#include "EntityManager.h"
#include "../Core/Shaders/shaderClass.h"
#include "../Component/Component.h"
#include "../Core/Shaders/EBO.h"
#include "../Core/Shaders/VAO.h"
#include "../Core/Shaders/VBO.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/quaternion.hpp>      
#include <glm/gtx/quaternion.hpp>     
#include "../Texture/Texture.h"


EntityManager::EntityManager() : EntityCount(0)
{
}

EntityManager::~EntityManager()
{
}

void EntityManager::Update()
{
}


void EntityManager::Render(const std::shared_ptr<Shader>& shader, glm::mat4 viewproj)
{
    shader->Activate();
    for (auto& entity : entities)
    {
        auto meshComponent = entity->GetComponent<MeshComponent>();
        if (meshComponent == nullptr)
            continue;

        auto transform = entity->GetComponent<TransformComponent>();
        if (transform == nullptr) continue;

        glm::mat4 model = glm::mat4(1.0f);
        glm::quat quaternion = glm::quat(transform->rotation);
        glm::mat4 rotationMatrix = glm::toMat4(quaternion);

        model = glm::translate(model, transform->position);
		model = glm::scale(model, transform->scale);
		model *= rotationMatrix;

        entity->vao->Bind();
        entity->vbo->Bind();
        entity->ebo->Bind();

        glDrawElements(GL_TRIANGLES, meshComponent->indices.size(), GL_UNSIGNED_INT, 0);

        entity->vao->Unbind();
        entity->vbo->Unbind();
        entity->ebo->Unbind();
    }
}




void EntityManager::ClearData()
{
}

bool EntityManager::HasNoEntities()
{
	return false;
}

void EntityManager::AddEntity(Entity& entity)
{
	if (entity.GetComponent<MeshComponent>() != nullptr)
	{
		initalizeMesh(entity);
	}
    entity.SetEntityID(EntityCount);
	++EntityCount;
	entities.push_back(&entity);
}

std::vector<Entity*> EntityManager::GetEntities() const
{
	return entities;
}

void EntityManager::initalizeMesh(Entity& entity)
{
    // Get the MeshComponent from the entity
    MeshComponent* meshComponent = entity.GetComponent<MeshComponent>();
    if (!meshComponent) {
        std::cerr << "Entity does not have a MeshComponent!" << std::endl;
        return;
    }

    // Binding the VAO
    entity.vao->Bind();
    entity.vbo->Bind();

    glBufferData(GL_ARRAY_BUFFER, meshComponent->vertices.size() * sizeof(Vertex), meshComponent->vertices.data(), GL_STATIC_DRAW);

    entity.vao->LinkAttrib(*entity.vbo, 0, 3, GL_FLOAT, sizeof(Vertex), (void*)offsetof(Vertex, x)); // Position
    entity.vao->LinkAttrib(*entity.vbo, 1, 3, GL_FLOAT, sizeof(Vertex), (void*)offsetof(Vertex, r)); // Color
    entity.vao->LinkAttrib(*entity.vbo, 2, 2, GL_FLOAT, sizeof(Vertex), (void*)offsetof(Vertex, u)); // TexCoords

    entity.ebo->Bind();
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, meshComponent->indices.size() * sizeof(unsigned int), meshComponent->indices.data(), GL_STATIC_DRAW);

    // Unbinding VAO, VBO, EBO
    entity.vao->Unbind();
    entity.vbo->Unbind();
    entity.ebo->Unbind();

}
