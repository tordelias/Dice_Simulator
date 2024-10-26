#include "EntityManager.h"

EntityManager::EntityManager() : EntityCount(0)
{
}

EntityManager::~EntityManager()
{
}

void EntityManager::Update()
{
}

void EntityManager::Render()
{
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
