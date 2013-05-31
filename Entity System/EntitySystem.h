#pragma once
#include "ComponentManager.h"
#include "System.h"
#include <vector>

class EntitySystem
{
public:
	EntitySystem(void);
	~EntitySystem(void);
	void update();
	void cleanup();
	void addSystem(System* system);
	void addComponent(Component*);
private:
	int currentEntityID;
	ComponentManager componentManager;
	std::vector<System*> systems;
};

