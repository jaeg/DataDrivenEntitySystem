#include "Component.h"


Component::Component(void)
{
	family = "base";
	ownerEntityId = -1;
}


Component::~Component(void)
{
}

std::string Component::getFamily()
{
	return family;
}

int Component::getOwnedEntityId()
{
	return ownerEntityId;
}

void Component::setFamily(std::string aFamily)
{
	family = aFamily;
}

void Component::setOwnerEntity(int aOwnerEntityId)
{
	ownerEntityId = aOwnerEntityId;
}