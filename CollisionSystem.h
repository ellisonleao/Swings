#ifndef __COLLISIONSYSTEM_H__
#define __COLLISIONSYSTEM_H__

#include "Entity.h"

class CollisionSystem
{
public:
	static bool entityCollidesWith(Entity *pSource, Entity *pDestiny);
private:
	CollisionSystem(void){};
	~CollisionSystem(void){};
};

#endif