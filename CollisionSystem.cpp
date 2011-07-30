#include "CollisionSystem.h"

bool CollisionSystem::entityCollidesWith(Entity *pSource, Entity *pDestiny)
{
	return ( pSource->getX() >= pDestiny->getX() && pSource->getX() < ( pDestiny->getX() + pDestiny->getWidth() ) &&
			 pSource->getY() >= pDestiny->getY() && pSource->getY() < ( pDestiny->getY() + pDestiny->getHeight() ) );
}