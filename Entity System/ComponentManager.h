#pragma once

#include <map>
#include <string>
#include "Component.h"


class ComponentManager
{
public:
	ComponentManager(void);
	~ComponentManager(void);
	void cleanup();
	std::map<int,Component*> getComponentCollectionByFamily(std::string family);

	template <class T>
	T* getComponent(std::string family, int entityId)
	{
		return dynamic_cast<T*>(componentsMap[family][entityId]);
	};

	void addComponent(Component* component);
	void removeComponent(std::string, int);

private:
	std::map<std::string,std::map<int,Component*>> componentsMap;
};

