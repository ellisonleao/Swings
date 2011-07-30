#ifndef __BULLET_H__
#define __BULLET_H__

#include "entity.h"

class Bullet :
	public Entity
{
public:

	Bullet();
	~Bullet(void);

	void show();
	void process(unsigned int time_passed);
	void erase();
	void draw();

	bool isDone();
	void setCollided();
private:
	unsigned int total_move_time;
	bool done;

	unsigned int move_time;
};

#endif
