#include "Bird.h"
#include "Console.h"
#include "defines.h"
#include <time.h>

Bird::Bird(void):
	Entity()
{
    srand(time(NULL));
	x = MAX_WIDTH;
	y = rand() % 20 - 3;
	width = 10;
	height = 3;
	done = false;
	total_move_time = MAX_WIDTH;

	move_time = 0;

	animation_frame = 0;
	total_animation_frames = 4;

	onCreateBulletListener = NULL;
}

Bird::~Bird(void)
{
	erase();
}


void Bird::process(unsigned int time_passed)
{
	if( !done )
	{
		move_time += time_passed;
		if( move_time >= total_move_time )
		{
			erase();
			move_time = 0;

			x -= 1;

			if ( x <= 1 )
				done = true;
			else
				draw();

			animation_frame++;
			animation_frame = animation_frame % total_animation_frames;
		}

	}
}

void Bird::draw()
{
    /*

  '. (v)  .'
    '( \.'
      ``\

    */

	switch(animation_frame)
	{
	default:
	case 0:
	case 4:
		mostrar(x, y, BACKGROUND_WHITE | FOREGROUND_CYAN,     "'. (v)  .'");
		mostrar(x, y +1 , BACKGROUND_WHITE | FOREGROUND_CYAN, "  '( \.'  ");
		mostrar(x, y + 2, BACKGROUND_WHITE | FOREGROUND_CYAN, "    ``\   ");
		break;
	case 1:
	case 3:
        mostrar(x, y, BACKGROUND_WHITE | FOREGROUND_CYAN,     "   (v)     ");
		mostrar(x, y +1 , BACKGROUND_WHITE | FOREGROUND_CYAN, "...( \...  ");
		mostrar(x, y + 2, BACKGROUND_WHITE | FOREGROUND_CYAN, "    ``\    ");
		break;
	case 2:
        mostrar(x, y, BACKGROUND_WHITE | FOREGROUND_WHITE,     "   (v)     ");
		mostrar(x, y +1 , BACKGROUND_WHITE | FOREGROUND_WHITE, "  .( \.    ");
		mostrar(x, y + 2, BACKGROUND_WHITE | FOREGROUND_WHITE, " /  ``\ \  ");
		break;
	}
}

void Bird::show()
{
	draw();
}

void Bird::erase()
{
	mostrar(x, y,     BACKGROUND_WHITE | FOREGROUND_WHITE, "          ");
	mostrar(x, y + 1, BACKGROUND_WHITE | FOREGROUND_WHITE, "          ");
    mostrar(x, y + 2, BACKGROUND_WHITE | FOREGROUND_WHITE, "          ");
}

bool Bird::isDone()
{
	return done;
}

void Bird::setCreateBulletListener(ICreateBulletListener *p_listener)
{
	onCreateBulletListener = p_listener;
}

void Bird::setBoundings(int pleft, int pright)
{
	bounding_left = pleft;
	bounding_right = pright;
}

void Bird::die()
{
	done = true;
}
