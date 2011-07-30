#include <conio.h>
#include "Plane.h"
#include "Console.h"
#include "defines.h"

Plane::Plane(void):
	Entity()
{
	onCreateBulletListener = NULL;
	width	= 22;
	height	= 4;
	total_shoot_timeout = 0;
	total_animation_frames = 1;
	animation_frame = 0;
	bounding_left = 0;
	bounding_right = 0;
}


Plane::~Plane(void)
{
	erase();
}

void Plane::draw()
{

	switch(animation_frame)
	{
        default:
        case 0:
            mostrar(x, y,     BACKGROUND_WHITE | FOREGROUND_INTENSITY, " /^\\____--/####\\___   ");
            mostrar(x, y +1 , BACKGROUND_WHITE | FOREGROUND_INTENSITY, "<_- _______         >@ ");
            mostrar(x, y + 2, BACKGROUND_WHITE | FOREGROUND_INTENSITY, "  @      ~~~~\\~\\~~~  ");
            mostrar(x, y + 3, BACKGROUND_WHITE | FOREGROUND_INTENSITY, "              @ @       ");
            break;
	}
}

void Plane::erase()
{
    mostrar(x, y,   BACKGROUND_WHITE | FOREGROUND_WHITE,"                  ");
    mostrar(x, y+1, BACKGROUND_WHITE | FOREGROUND_WHITE,"                   ");
    mostrar(x, y+2, BACKGROUND_WHITE | FOREGROUND_WHITE,"                  ");
    mostrar(x, y+3, BACKGROUND_WHITE | FOREGROUND_WHITE,"                  ");
}

void Plane::process(unsigned int time_passed)
{

	if (kbhit())
	{
		char c = getch();

		switch(c)
		{
		case 'a': // left
			move(-1,0);
			break;
		case 'd': // right
			move(1,0);
			break;
		case 'w': //up
            move(0,-1);
            break;
        case 's': //down
            move(0,1);
            break;
		case 32: //space
            shoot();
			draw();
			break;
		}
	}
}
//implementar movimento vertical no move
void Plane::move(int dx, int dy)
{
    erase();
	x += dx;
	y += dy;

	if (y > MAX_HEIGHT) //nao descer
        y = MAX_HEIGHT - height;
    if (y < 3) //nao subir
        y = 3;

	draw();
}

void Plane::show()
{
	draw();
}

void Plane::shoot()
{
    PlaySound("shot.wav",NULL,SND_FILENAME|SND_ASYNC);
    if( NULL != onCreateBulletListener )
        onCreateBulletListener->onCreateBullet(x + width, y );
}

void Plane::setCreateBulletListener(ICreateBulletListener *p_listener)
{
	onCreateBulletListener = p_listener;
}

void Plane::setBoundings(int pleft, int pright)
{
	bounding_left = pleft;
	bounding_right = pright;
}
