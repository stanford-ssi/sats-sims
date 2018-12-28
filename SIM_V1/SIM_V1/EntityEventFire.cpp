#include "EntityEventFire.h"

using namespace EE;

oid EntityEventFire::fireEntityAdd(const eId& id, Entity const* const address)
{
	entityAddComponentEvent(id, address);
}

void EntityEventFire::fireEntityRemove(EE::System* const currSys, const eId& id)
{
	entityRemoveSignal(currSys, id);
}