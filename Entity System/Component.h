#pragma once
#include <string>
class Component
{
public:
	Component(void);
	~Component(void);
	std::string getFamily();
	int getOwnedEntityId();

	void setFamily(std::string);
	void setOwnerEntity(int id);
protected:
	std::string family;
	int ownerEntityId;
};

