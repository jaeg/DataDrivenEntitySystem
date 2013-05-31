#pragma once
#include "Component.h"
#include "ComponentManager.h"

class System
{
public:
	System(void);
	~System(void);
	virtual void init();
	virtual void update();
	virtual void cleanup();
	void setComponentManager(ComponentManager*);
protected:
	ComponentManager* componentManager;
};

