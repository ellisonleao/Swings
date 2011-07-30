#ifndef __PLANE_HPP__
#define __PLANE_HPP__

#include "entity.h"
#include "ICreateBulletListener.h"

class Plane :
	public Entity
{
private:
	ICreateBulletListener *onCreateBulletListener;
	unsigned int total_shoot_timeout;
	unsigned int shoot_timeout;
	int bounding_left;
	int bounding_right;
	int animation_frame;
	int total_animation_frames;
public:
	Plane(void);
	~Plane(void);

	void show();
	void process(unsigned int time_passed);
	void draw();
	void erase();
	void move(int px,int py);

	void shoot();
	void reset();

	void setCreateBulletListener(ICreateBulletListener *p_listener);
	void setBoundings(int pleft, int pright);
};

#endif
