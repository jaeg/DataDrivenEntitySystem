#include "ComponentManager.h"


ComponentManager::ComponentManager(void)
{
}


ComponentManager::~ComponentManager(void)
{
}

std::map<int,Component*>* ComponentManager::getComponentCollectionByFamily(std::string family)
{
	return &componentsMap[family];
}

Component* ComponentManager::getComponent(std::string family, int entityId)
{
	return componentsMap[family][entityId];
}

void ComponentManager::addComponent(Component* component)
{
	std::string family = component->getFamily();
	int ownerEntity = component->getOwnedEntityId();

	componentsMap[family][ownerEntity] = component;
}