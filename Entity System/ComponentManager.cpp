#include "ComponentManager.h"


ComponentManager::ComponentManager(void)
{
}


ComponentManager::~ComponentManager(void)
{
}

void ComponentManager::cleanup()
{
	typedef std::map<std::string,std::map<int,Component*>>::iterator familyIterator;
	typedef std::map<int,Component*>::iterator componentIterator;

	for (familyIterator i = componentsMap.begin(); i != componentsMap.end(); i++)
	{
		std::map<int,Component*>* components = &i->second;
		for (componentIterator j = components->begin(); j !=  components->end(); j++)
		{
			delete j->second;
			j->second = NULL;
		}
	}
}

void ComponentManager::removeComponent(std::string family, int owner)
{
	delete componentsMap[family][owner];
	componentsMap[family][owner] = NULL;
}

std::map<int,Component*> ComponentManager::getComponentCollectionByFamily(std::string family)
{
	return componentsMap[family];
}


void ComponentManager::addComponent(Component* component)
{
	std::string family = component->getFamily();
	int ownerEntity = component->getOwnedEntityId();

	componentsMap[family][ownerEntity] = component;
}