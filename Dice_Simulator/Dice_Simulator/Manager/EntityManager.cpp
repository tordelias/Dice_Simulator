#pragma once
#include "EntityManager.h"
#include "../Core/Shaders/shaderClass.h"
#include "../Component/Component.h"
#include "../Core/Shaders/EBO.h"
#include "../Core/Shaders/VAO.h"
#include "../Core/Shaders/VBO.h"
#include <glm/gtc/matrix_transform.hpp>


EntityManager::EntityManager() : EntityCount(0)
{
}

EntityManager::~EntityManager()
{
}

void EntityManager::Update()
{
}

void EntityManager::Render(const std::shared_ptr<Shader>& Shader, glm::mat4 viewproj, TransformComponent& pos)
{
	for (auto& entity : entities)
    {
        glm::mat4 model2 = glm::mat4(1.0f);

        //glm::quat quaterninon = glm::quat(0.0, 0.0, 0.0, 0.0);
        //glm::mat4 rotationMatrix = glm::mat4_cast(quaterninon);
        model2 = glm::translate(model2, pos.position);
        model2 = glm::scale(model2, pos.scale);
        model2 *= pos.rotation;

		entity->vao->Bind();
        entity->vbo->Bind();
        entity->ebo->Bind();

        glDrawElements(GL_TRIANGLES, entity->GetComponent<MeshComponent>().indices.size(), GL_UNSIGNED_INT, 0);
        // glDrawArrays(GL_POINT, 0, vertices.size());
         //unbind
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

//Entity& EntityManager::AddEntity(int EntityID)
//{
//	// TODO: insert return statement here
//}

std::vector<Entity*> EntityManager::GetEntities() const
{
	return std::vector<Entity*>();
}
