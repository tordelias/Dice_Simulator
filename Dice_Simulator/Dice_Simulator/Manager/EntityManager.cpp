#pragma once
#define GLM_ENABLE_EXPERIMENTAL
#include "EntityManager.h"
#include "../Resources/Shaders/shaderClass.h"
#include "../Component/Component.h"
#include "../Resources/Shaders/EBO.h"
#include "../Resources/Shaders/VBO.h"
#include "../Resources/Shaders/VAO.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/quaternion.hpp>      
#include <glm/gtx/quaternion.hpp>     
#include "../Resources/Texture/Texture.h"
#include <glm/gtc/type_ptr.hpp>
#include "../Resources/Texture/Texture.h"


EntityManager::EntityManager(std::shared_ptr<Shader> shaderprogram) : EntityCount(0)
{
	shader = shaderprogram;
}

EntityManager::~EntityManager()
{
}

void EntityManager::Update()
{
}


void EntityManager::Render(glm::mat4 viewproj)
{
    int textureCount = 0;
    for (auto& entity : entities)
    {
        auto meshComponent = entity->GetComponent<MeshComponent>();
        if (meshComponent == nullptr)
            continue;

        auto transform = entity->GetComponent<TransformComponent>();
        if (transform == nullptr) continue;

        // Model matrix calculations
        glm::mat4 model = glm::mat4(1.0f);
        glm::quat quaternion = glm::quat(transform->rotation);
        glm::mat4 rotationMatrix = glm::toMat4(quaternion);

        model = glm::translate(model, transform->position);
        model = glm::scale(model, transform->scale);
        model *= rotationMatrix;

        glUniformMatrix4fv(glGetUniformLocation(shader->ID, "camMatrix"), 1, GL_FALSE, glm::value_ptr(viewproj * model));

        bool hasTexture = meshComponent->TexturePath != "";
		glUniform1i(glGetUniformLocation(shader->ID, "useTexture"), hasTexture); // Set useTexture to true if the entity has a texture

        if (hasTexture) {
            glBindTexture(GL_TEXTURE_2D, textures[textureCount].texture);
            textureCount++;
        }
        else {
            glBindTexture(GL_TEXTURE_2D, 0);
        }

        // Bind VAO, VBO, and EBO for drawing
        entity->vao->Bind();
        entity->vbo->Bind();
        entity->ebo->Bind();

        glDrawElements(GL_TRIANGLES, meshComponent->indices.size(), GL_UNSIGNED_INT, 0);

        // Unbind VAO, VBO, and EBO after drawing
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

void EntityManager::AddEntity(std::shared_ptr<Entity>& entity)
{
    if (entity->GetComponent<MeshComponent>() != nullptr)
    {
        initalizeMesh(entity);
    }
    entity->SetEntityID(EntityCount);
    ++EntityCount;
	entities.push_back(entity.get());
}

std::vector<Entity*> EntityManager::GetEntities() const
{
    return entities;
}

void EntityManager::initalizeMesh(std::shared_ptr<Entity>& entity)
{
    MeshComponent* meshComponent = entity->GetComponent<MeshComponent>();
    if (!meshComponent) {
        std::cerr << "Entity does not have a MeshComponent!" << std::endl;
        return;
    }
	initalizeTexture(entity);

    // Binding the VAO
    entity->vao->Bind();
    entity->vbo->Bind();

    glBufferData(GL_ARRAY_BUFFER, meshComponent->vertices.size() * sizeof(Vertex), meshComponent->vertices.data(), GL_STATIC_DRAW);

    entity->vao->LinkAttrib(*entity->vbo, 0, 3, GL_FLOAT, sizeof(Vertex), (void*)offsetof(Vertex, x)); // Position
    entity->vao->LinkAttrib(*entity->vbo, 1, 3, GL_FLOAT, sizeof(Vertex), (void*)offsetof(Vertex, r)); // Color
    entity->vao->LinkAttrib(*entity->vbo, 2, 2, GL_FLOAT, sizeof(Vertex), (void*)offsetof(Vertex, u)); // TexCoords

    entity->ebo->Bind();
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, meshComponent->indices.size() * sizeof(unsigned int), meshComponent->indices.data(), GL_STATIC_DRAW);

    // Unbinding VAO, VBO, EBO
    entity->vao->Unbind();
    entity->vbo->Unbind();
    entity->ebo->Unbind();
}

void EntityManager::initalizeTexture(std::shared_ptr<Entity>& entity)
{
	MeshComponent* meshComponent = entity->GetComponent<MeshComponent>();
	if (!meshComponent) {
		std::cerr << "Entity does not have a MeshComponent!" << std::endl;
		return;
	}

	Texture texture(meshComponent->TexturePath, shader);
	textures.push_back(texture);
}

