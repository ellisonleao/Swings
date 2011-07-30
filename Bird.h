#ifndef __BIRD_H__
#define __BIRD_H__

#include "entity.h"
#include "ICreateBulletListener.h"

class Bird :
	public Entity
{
private:
	bool done;
	unsigned int move_time;
	ICreateBulletListener *onCreateBulletListener;
	unsigned int total_move_time;
	unsigned int total_shoot_time;

	int bounding_left;
	int bounding_right;
	int animation_frame;
	int total_animation_frames;
public:
	Bird(void);
	~Bird(void);

	void process(unsigned int time_passed);
	void draw();
	void show();
	void erase();

	bool isDone();

	void setCreateBulletListener(ICreateBulletListener *p_listener);
	void setBoundings(int pleft, int pright);

	void die();
};

#endif
