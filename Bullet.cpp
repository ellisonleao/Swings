#include "Bullet.h"
#include "defines.h"
#include "Console.h"

Bullet::Bullet():
	Entity()
{
	width	= 1;
	height	= 1;
	done	= false;
	move_time = 0;
	total_move_time = MAX_WIDTH;
}

Bullet::~Bullet(void)
{
	erase();
}

void Bullet::show()
{
	draw();
}

void Bullet::process(unsigned int time_passed)
{
	if( !done )
	{
		move_time += time_passed;

		if( move_time >= total_move_time )
		{
			move_time = 0;

			erase();
			x += 1;

			if( x > ( MAX_WIDTH ) )
				done = true;
			else
				draw();
		}
	}
}

void Bullet::erase()
{
	mostrar(x, y+1, BACKGROUND_WHITE | FOREGROUND_WHITE, " ");
}

void Bullet::draw()
{
	mostrar(x, y+1, BACKGROUND_WHITE | FOREGROUND_RED , "@");
}


bool Bullet::isDone()
{
	return done;
}

void Bullet::setCollided()
{
	done = true;
}
