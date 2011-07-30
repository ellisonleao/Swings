#include "Scene.h"
#include "Console.h"
#include "defines.h"
#include "CollisionSystem.h"
#include <stdio.h>
#include <time.h>

Scene::Scene(void)
{
	plane.setCreateBulletListener(this);
	total_birds_spawn_time = 0;
	birds_spawn_time = 0;
	distance = 40;
	lifes = 4;

	time_to_act = 0;
	landed = false;
}

Scene::~Scene(void)
{
	clearLists();
}

void Scene::reset()
{
	clearLists();
	total_birds_spawn_time = 0;
	birds_spawn_time = 0;
	game_over = false;
	landed = false;
	points = 0;
	distance = 60;
	lifes = 4;
	updatePoints();
	multiplier = 1;
}

void Scene::process(unsigned int time_passed)
{

	plane.process(time_passed);
	Plane* pPlane = &plane;


	std::list<Bullet *>::iterator i;
	char distance_str[10] = "";

    //verifica distancia
    time_to_act += time_passed;
    if (time_to_act >= 1000) //1segundo
    {
        distance--;
        time_to_act = 0;
        if (distance == 0)
        {
            landed = true;
        }
        sprintf(distance_str, "%2d", distance);
        mostrar(MAX_WIDTH - 5 ,1, BACKGROUND_WHITE | FOREGROUND_RED, distance_str);
    }

	for(i = bullets.begin(); i != bullets.end(); ++i)
	{
		Bullet *bullet = (*i);
		bullet->process(time_passed);
		verifyBulletHit(bullet);

		if( bullet->isDone() )
		{
			points += 1 * multiplier;
			updatePoints();

			bullets.remove(bullet);
			delete bullet;
			break;
		}
	}

	birds_spawn_time += time_passed;

	if( birds_spawn_time >= total_birds_spawn_time )
	{
		birds_spawn_time = 0;
		total_birds_spawn_time = ( rand() % 2000 ) + 1000;
		createBird();
	}

	std::list<Bird *>::iterator e;
	for(e = birds.begin(); e != birds.end(); ++e)
	{
		Bird *bird = (*e);
		bird->process(time_passed);
        verifyBirdHit(pPlane);
        if (lifes == 0){
            game_over = true;
        }
        //TODO: verificar se passaro colidiu com aviao
		if( bird->isDone() )
		{
			birds.remove(bird);
			delete bird;
			break;
		}
	}
}

void Scene::createBird()
{
    srand(time(NULL));
	Bird *bird = new Bird();
	bird->setPosition(MAX_WIDTH, rand() % 20 + 2);
	bird->show();
	//bird->setCreateBulletListener(this);
	bird->setBoundings(MAX_WIDTH, MAX_HEIGHT - 3);

	birds.push_back(bird);
}


void Scene::menuLoopClouds(){
    int i;
    //move pra direita
    for (i = 1 ; i <= 15 ; i++){
        mostrar(i, 0,BACKGROUND_WHITE | FOREGROUND_BLUE,"                _                                       ");
        mostrar(i, 1,BACKGROUND_WHITE | FOREGROUND_BLUE,"             (`  ).                   _                 ");
        mostrar(i, 2,BACKGROUND_WHITE | FOREGROUND_BLUE,"           (     ).              .:(`  )`.              ");
        mostrar(i, 3,BACKGROUND_WHITE | FOREGROUND_BLUE,"            _(       '`.          :(   .    )           ");
        mostrar(i, 4,BACKGROUND_WHITE | FOREGROUND_BLUE,"        .=(`(      .   )     .--  `.  (    ) )          ");
        mostrar(i, 5,BACKGROUND_WHITE | FOREGROUND_BLUE,"       ((    (..__.:'-'   .+(   )   ` _`  ) )           ");
        mostrar(i, 6,BACKGROUND_WHITE | FOREGROUND_BLUE,"       `(       ) )       (   .  )     (   )  ._        ");
        mostrar(i, 7,BACKGROUND_WHITE | FOREGROUND_BLUE,"         ` __.:'   )     (   (   ))     `-'.-(`  )      ");
        mostrar(i, 8,BACKGROUND_WHITE | FOREGROUND_BLUE,"                --'       `- __.'         :(      ))    ");
        mostrar(i, 9,BACKGROUND_WHITE | FOREGROUND_BLUE,"                   .')                    `(    )  ))   ");
        mostrar(i, 10,BACKGROUND_WHITE | FOREGROUND_BLUE,"                  (_  )                     ` __.:'    ");
        Sleep(120);
    }

    //move esquerda
    for (i = 14 ; i > 1 ; i--){
        mostrar(i, 0,BACKGROUND_WHITE | FOREGROUND_BLUE,"                _                                       ");
        mostrar(i, 1,BACKGROUND_WHITE | FOREGROUND_BLUE,"             (`  ).                   _                 ");
        mostrar(i, 2,BACKGROUND_WHITE | FOREGROUND_BLUE,"           (     ).              .:(`  )`.              ");
        mostrar(i, 3,BACKGROUND_WHITE | FOREGROUND_BLUE,"            _(       '`.          :(   .    )           ");
        mostrar(i, 4,BACKGROUND_WHITE | FOREGROUND_BLUE,"        .=(`(      .   )     .--  `.  (    ) )          ");
        mostrar(i, 5,BACKGROUND_WHITE | FOREGROUND_BLUE,"       ((    (..__.:'-'   .+(   )   ` _`  ) )           ");
        mostrar(i, 6,BACKGROUND_WHITE | FOREGROUND_BLUE,"       `(       ) )       (   .  )     (   )  ._        ");
        mostrar(i, 7,BACKGROUND_WHITE | FOREGROUND_BLUE,"         ` __.:'   )     (   (   ))     `-'.-(`  )      ");
        mostrar(i, 8,BACKGROUND_WHITE | FOREGROUND_BLUE,"                --'       `- __.'         :(      ))    ");
        mostrar(i, 9,BACKGROUND_WHITE | FOREGROUND_BLUE,"                   .')                    `(    )  ))   ");
        mostrar(i, 10,BACKGROUND_WHITE | FOREGROUND_BLUE,"                  (_  )                     ` __.:'    ");
        Sleep(120);
    }
}


void Scene::show()
{
	game_over = false;
	landed = false;
	clrscr(BACKGROUND_WHITE);
	mostrar(0, 0, BACKGROUND_BLUE | FOREGROUND_WHITE, "Lives:\t\t\t\t\t\t\t\t\tScore:");
    mostrar(MAX_WIDTH - 20,1, BACKGROUND_WHITE | FOREGROUND_GREEN, "Safe Distance: ");
    mostrar(MAX_WIDTH - 2,1, BACKGROUND_WHITE | FOREGROUND_GREEN, "km");

	plane.setPosition(0, 12);
	plane.setBoundings(MAX_WIDTH, MAX_HEIGHT- 3);
	plane.show();
}

void Scene::onCreateBullet(int px, int py)
{
	Bullet *bullet = new Bullet();
	bullet->setPosition(px, py);
	bullet->show();

	bullets.push_back(bullet);
}

bool Scene::isGameOver()
{
	return game_over;
}

bool Scene::isLanded()
{
	return landed;
}

void Scene::verifyBulletHit(Bullet *pBullet)
{
    std::list<Bird*>::iterator i;
    std::list<Bird*>::iterator end = birds.end();

    for(i = birds.begin(); i != end; ++i)
    {
        if(CollisionSystem::entityCollidesWith(pBullet, (*i)))
        {
			pBullet->setCollided();
			(*i)->die();
			PlaySound("birdhit.wav",NULL,SND_FILENAME|SND_ASYNC);
			multiplier++;
			break;
		}
    }
}


void Scene::verifyBirdHit(Plane *pPlane)
{
    char lifes_str[4] = "";
    sprintf(lifes_str, "%2d", lifes);
    mostrar(7,0, BACKGROUND_BLUE | FOREGROUND_WHITE, lifes_str);
    std::list<Bird*>::iterator i;
    std::list<Bird*>::iterator end = birds.end();

    for(i = birds.begin(); i != end; ++i)
    {
        if(CollisionSystem::entityCollidesWith((*i), pPlane ))
        {
			(*i)->die();
			PlaySound("planehit.wav",NULL,SND_FILENAME|SND_ASYNC);
			lifes--;
			break;
		}
    }
}




void Scene::updatePoints()
{
	char points_str[10] = "";
	sprintf(points_str, "%07d", points);
	mostrar(MAX_WIDTH - 6, 0, BACKGROUND_BLUE | FOREGROUND_WHITE, points_str);
}

void Scene::clearLists()
{
	while(!bullets.empty())
	{
		std::list<Bullet*>::iterator i = bullets.begin();
		Bullet *bullet = (*i);

		bullets.remove(bullet);

		delete bullet;
	}

	while(!birds.empty())
	{
		std::list<Bird*>::iterator i = birds.begin();
		Bird *bird = (*i);

		birds.remove(bird);

		delete bird;
	}
}

unsigned int Scene::getPoints()
{
	return points;
}
