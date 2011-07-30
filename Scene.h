#ifndef __SCENE_HPP__
#define __SCENE_HPP__

#include <list>
#include "Plane.h"
#include "Bullet.h"
#include "ICreateBulletListener.h"
#include "Bird.h"


class Scene :
	ICreateBulletListener
{
private:
	std::list<Bullet*> bullets;
	std::list<Bird*> birds;
	Plane plane;

	unsigned int birds_spawn_time;
	bool game_over;
	bool landed;
	unsigned int points;
	unsigned int multiplier;
	int distance;
	int time_to_act;
	int lifes;
	void updatePoints();
public:
	unsigned int total_birds_spawn_time;
	Scene(void);
	~Scene(void);

	void process(unsigned int time_passed);
	void show();

	void onCreateBullet(int px, int py);
	void verifyBulletHit(Bullet *pBullet);
	void verifyBirdHit(Plane *plane);
	void createBird();
    void menuLoopClouds();
	bool isGameOver();
	bool isLanded();
	void reset();
	void clearLists();
	unsigned int getPoints();
};

#endif
