#ifndef __ICREATEBULLETLISTENER_HPP__
#define __ICREATEBULLETLISTENER_HPP__

#include "Bullet.h"
class ICreateBulletListener
{
public:
	ICreateBulletListener(void);
	~ICreateBulletListener(void);

	virtual void onCreateBullet(int px, int py)=0;
};

#endif
