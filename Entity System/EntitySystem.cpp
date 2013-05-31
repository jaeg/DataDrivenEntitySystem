#include "EntitySystem.h"


EntitySystem::EntitySystem(void)
{
}


EntitySystem::~EntitySystem(void)
{
}


void EntitySystem::update()
{
	for (unsigned int i = 0; i < systems.size(); i++)
	{
		systems[i]->update();
	}
}

void EntitySystem::cleanup()
{
	for (unsigned int i = 0; i < systems.size(); i++)
	{
		systems[i]->cleanup();
		delete systems[i];
	}

	componentManager.cleanup();
}

void EntitySystem::addSystem(System* system)
{
	system->init();
	system->setComponentManager(&componentManager);
	systems.push_back(system);
}

void EntitySystem::addComponent(Component* component)
{
	componentManager.addComponent(component);
}