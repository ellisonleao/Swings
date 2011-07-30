#ifndef __GAMEMANAGER_H__
#define __GAMEMANAGER_H__

#include "Scene.h"

class GameManager
{
private:
	enum GAME_STATE
	{
		STATE_MENU,
		STATE_GAME
	};

	int points;
	GAME_STATE state;
	Scene scene;
	unsigned int tick;

	void loop();
	void showGameOver();
	void showLanding();
public:
	GameManager(void);
	~GameManager(void);

	void run();

	GAME_STATE getCurrentState();
};

#endif
