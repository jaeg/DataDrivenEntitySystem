#pragma once
#include <map>;
#include <string>;
#include "Component.h";
class ComponentManager
{
public:
	ComponentManager(void);
	~ComponentManager(void);
	std::map<int,Component*>* getComponentCollectionByFamily(std::string family);
	Component* getComponent(std::string family, int entityId);
	void addComponent(Component* component);

private:
	std::map<std::string,std::map<int,Component*>> componentsMap;
};

