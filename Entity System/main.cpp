#include <iostream>
#include "Component.h"
#include "ComponentManager.h"

using namespace std;

int main()
{
	ComponentManager componentManager;

	Component* component = new Component();
	component->setOwnerEntity(0);

	componentManager.addComponent(component);

	component = new Component();
	component->setOwnerEntity(1);

	componentManager.addComponent(component);

	component = new Component();
	component->setOwnerEntity(0);
	component->setFamily("base2");

	componentManager.addComponent(component);

	cout<<"Component 1 Family = Base, Entity Id = 0: Results:"<<componentManager.getComponent<Component>("base",0)<<" Expected: memory location\n";
	cout<<"Component 2 Family = Base, Entity Id = 1: Results:"<<componentManager.getComponent<Component>("base",1)<<" Expected: memory location\n";
	cout<<"Component 3 Family = Base, Entity Id = 2: Results:"<<componentManager.getComponent<Component>("base" , 2)<<" Expected: 000000 or NULL\n";
	cout<<"Component 4 Family = NA, Entity Id = 0: Results:"<<componentManager.getComponent<Component>("NA", 0)<<" Expected: 000000 or NULL\n";
	cout<<"Component 4 Family = base2, Entity Id = 0: Results:"<<componentManager.getComponent<Component>("base2", 0)<<" Expected: memory location\n";
	componentManager.removeComponent("base", 0);
	cout<<"Component 1 Family = Base, Entity Id = 0: Results:"<<componentManager.getComponent<Component>("base",0)<<" Expected: NULL\n";
	
	int stall;
	cin >> stall;
	return 0;
}