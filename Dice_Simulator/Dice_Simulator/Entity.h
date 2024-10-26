#pragma once
#include <memory>
#include <iostream>
#include "Core/Shaders/EBO.h"
#include "Core/Shaders/VAO.h"
#include "Core/Shaders/VBO.h"

class Entity
{
	int EntityID;
public:
	Entity();
	~Entity();
	void Destroy();
	bool IsActive() const;
	void ListAllComponents() const;
	template <typename T>
	bool HasComponent() const;
	template <typename T, typename... TArgs>
	T& AddComponent(TArgs&&... args);
	template <typename T>
	T& GetComponent() const;
	
	std::shared_ptr<VAO> vao;
	std::shared_ptr<VBO> vbo;
	std::shared_ptr<EBO> ebo;
};

template<typename T>
inline bool Entity::HasComponent() const
{
	return false;
}

template<typename T, typename ...TArgs>
inline T& Entity::AddComponent(TArgs && ...args)
{
	// TODO: insert return statement here
}

template<typename T>
inline T& Entity::GetComponent() const
{
	// TODO: insert return statement here
}
