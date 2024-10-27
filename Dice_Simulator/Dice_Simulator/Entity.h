#pragma once
#include <memory>
#include <iostream>
#include "Core/Shaders/EBO.h"
#include "Core/Shaders/VAO.h"
#include "Core/Shaders/VBO.h"
#include "Component/Component.h"
#include <unordered_map>
#include <typeindex>

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
    T* GetComponent() const;

    void SetEntityID(int id) { EntityID = id; };
    int GetEntityID() { return EntityID; };

    std::shared_ptr<VAO> vao;
    std::shared_ptr<VBO> vbo;
    std::shared_ptr<EBO> ebo;
private:
    std::unordered_map<std::type_index, std::unique_ptr<Component>> components;
};

template<typename T>
inline bool Entity::HasComponent() const
{
    return components.find(typeid(T)) != components.end();
}

template<typename T, typename ...TArgs>
inline T& Entity::AddComponent(TArgs && ...args)
{
    auto component = std::make_unique<T>(std::forward<TArgs>(args)...);
    components[typeid(T)] = std::move(component);
    return *static_cast<T*>(components[typeid(T)].get());
}

template<typename T>
T* Entity::GetComponent() const
{
    auto it = components.find(typeid(T));
    return (it != components.end()) ? dynamic_cast<T*>(it->second.get()) : nullptr;
}
