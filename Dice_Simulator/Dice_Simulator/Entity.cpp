#include "Entity.h"

Entity::Entity() : vao(std::make_shared<VAO>()), vbo(std::make_shared<VBO>()), ebo(std::make_shared<EBO>()), EntityID(0), components()
{
}

Entity::~Entity()
{
}

void Entity::Destroy()
{
}

bool Entity::IsActive() const
{
	return false;
}

void Entity::ListAllComponents() const
{
}
