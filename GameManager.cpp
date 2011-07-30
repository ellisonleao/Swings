#include <conio.h>
#include <stdio.h>
#include <time.h>
#include "GameManager.h"
#include "Console.h"
#include "defines.h"
#include <stdlib.h>
#include <Windows.h>

#pragma comment(lib,"Winmm.lib")

GameManager::GameManager(void)
{
	points = 0;
	tick = GetTickCount();
}

GameManager::~GameManager(void)
{
}

void GameManager::run()
{
	state = STATE_MENU;


    clrscr(BACKGROUND_WHITE);
    PlaySound("theme.wav",NULL,SND_FILENAME|SND_LOOP|SND_ASYNC);
	mostrar(4, 12,BACKGROUND_WHITE | FOREGROUND_BLUE,  " ::::::::  :::       ::: ::::::::::: ::::    :::  ::::::::   ::::::::  ");
	mostrar(4, 13,BACKGROUND_WHITE | FOREGROUND_BLUE,  ":+:    :+: :+:       :+:     :+:     :+:+:   :+: :+:    :+: :+:    :+: ");
	mostrar(4, 14,BACKGROUND_WHITE | FOREGROUND_BLUE,  "+:+        +:+       +:+     +:+     :+:+:+  +:+ +:+        +:+        ");
	mostrar(4, 15,BACKGROUND_WHITE | FOREGROUND_CYAN,  "+#++:++#++ +#+  +:+  +#+     +#+     +#+ +:+ +#+ :#:        +#++:++#++ ");
	mostrar(4, 16,BACKGROUND_WHITE | FOREGROUND_RED,   "       +#+ +#+ +#+#+ +#+     +#+     +#+  +#+#+# +#+   +#+#        +#+ ");
	mostrar(4, 17,BACKGROUND_WHITE | FOREGROUND_RED,   "#+#    #+#  #+#+# #+#+#      #+#     #+#   #+#+# #+#    #+# #+#    #+# ");
	mostrar(4, 18,BACKGROUND_WHITE | FOREGROUND_YELLOW," ########    ###   ###   ########### ###    ####  ########   ########");

	//MENU
	mostrar(25,20, BACKGROUND_WHITE| FOREGROUND_BLUE, "A fight for safe wings on the sky..");
	mostrar(10,21, BACKGROUND_WHITE| FOREGROUND_BLUE, "Use WASD to move and SPACE to shoot. Don't get caught by the birds..");
	do{
        scene.menuLoopClouds();
	}while (!kbhit());

	char c = getch();
	state = STATE_GAME;
    PlaySound(NULL,0,0);
	c = 0;


	while(c != 'q')
	{
	    PlaySound("moving.wav",NULL,SND_FILENAME|SND_LOOP|SND_ASYNC|SND_NOSTOP);
		scene.show();
		scene.reset();
		loop();

		do{
			c = getch();
		}while(c != ESC);
	}
}

void GameManager::loop()
{
	do
	{
		unsigned int current_tick = GetTickCount();
		unsigned int time_passed = current_tick - tick;

		scene.process(time_passed);

		char c = 0;

		if(scene.isGameOver())
		{
		    PlaySound("crash.wav",NULL,SND_FILENAME|SND_ASYNC);
		    PlaySound("fail.wav",NULL,SND_FILENAME|SND_ASYNC);
			showGameOver();
			break;
		}

        if(scene.isLanded())
		{
			showLanding();
			PlaySound("theme.wav",NULL,SND_FILENAME|SND_LOOP|SND_ASYNC);
			break;
		}

		tick = current_tick;

	}while(1);
}

GameManager::GAME_STATE GameManager::getCurrentState()
{
	return state;
}

void GameManager::showGameOver()
{
	unsigned int points = scene.getPoints();
	char points_str[7] = "";
	sprintf(points_str, "%06d", points);

    mostrar(3, 4, BACKGROUND_WHITE | FOREGROUND_RED,"             @@@                           ");
    mostrar(3, 5, BACKGROUND_WHITE | FOREGROUND_RED,"               @@@   \\         /  *       ");
    mostrar(3, 6, BACKGROUND_WHITE | FOREGROUND_RED,"                __@**__\\_/0\_/______*     ");
    mostrar(3, 7, BACKGROUND_WHITE | FOREGROUND_RED,"                   %%  \\_\\v/_/  @        ");
    Sleep(400);
    clrscr(BACKGROUND_WHITE);
    mostrar(4, 8, BACKGROUND_WHITE | FOREGROUND_RED,"                                 @*        ");
    mostrar(4, 9, BACKGROUND_WHITE | FOREGROUND_RED,"                              \\   |% *     ");
    mostrar(4, 10, BACKGROUND_WHITE | FOREGROUND_RED,"                         @@  *  \\ ||\\     ");
    mostrar(4, 11, BACKGROUND_WHITE | FOREGROUND_RED,"                        @@@@     /~ \| *   ");
    mostrar(4, 12, BACKGROUND_WHITE | FOREGROUND_RED,"                           @@@@  \\_ /|    ");
    mostrar(4, 13, BACKGROUND_WHITE | FOREGROUND_RED,"                              @@/*||/      ");
    mostrar(4, 14, BACKGROUND_WHITE | FOREGROUND_RED,"                              /  @@*%      ");
    mostrar(4, 15, BACKGROUND_WHITE | FOREGROUND_RED,"                                 %|        ");
    Sleep(400);
    clrscr(BACKGROUND_WHITE);
    mostrar(0, 16, BACKGROUND_WHITE | FOREGROUND_RED,"                                           @@@            ");
    mostrar(0, 17, BACKGROUND_WHITE | FOREGROUND_RED,"                                          @@@@@           ");
    mostrar(0, 18, BACKGROUND_WHITE | FOREGROUND_RED,"                                             @@@@         ");
    mostrar(0, 19, BACKGROUND_WHITE | FOREGROUND_RED,"                            @@@      *   **     @@@       ");
    mostrar(0, 20, BACKGROUND_WHITE | FOREGROUND_RED,"                              @@@ %  *  /~/^\\~\\  @@@    ");
    mostrar(0, 21, BACKGROUND_WHITE | FOREGROUND_RED,"                                 *#~~~~~/~\\0/~\\~~~*@*~  ");
    mostrar(0, 22, BACKGROUND_WHITE | FOREGROUND_RED,"                                    * /  *    %**%        ");
    mostrar(0, 23, BACKGROUND_WHITE | FOREGROUND_RED,"                                              ##**        ");
    Sleep(400);
    clrscr(BACKGROUND_WHITE);
    mostrar(0, 16, BACKGROUND_WHITE | FOREGROUND_RED,"                                @@@@@@@@@    @@@@@    @@@@         ");
    mostrar(0, 17, BACKGROUND_WHITE | FOREGROUND_RED,"                              @@@@@@@@@@@@@@@@@@@@@ @@@@@@@@        ");
    mostrar(0, 18, BACKGROUND_WHITE | FOREGROUND_RED,"                                @@@@@@@@@@@   @@@@@@   @@@@@@@      ");
    mostrar(0, 19, BACKGROUND_WHITE | FOREGROUND_RED,"                                    @@@@@@@       @@@@@     @@@     ");
    mostrar(0, 20, BACKGROUND_WHITE | FOREGROUND_RED,"                                         @@@@@        @@@@@    @@   ");
    mostrar(0, 21, BACKGROUND_WHITE | FOREGROUND_RED,"                                           @@@@@@@      @@@@@   @@@ ");
    mostrar(0, 22, BACKGROUND_WHITE | FOREGROUND_RED,"                                              @@@@@ `' { @{@)(` @@  ");
    mostrar(0, 23, BACKGROUND_WHITE | FOREGROUND_RED,"                                          '`  '`@#@\ |**@%'~`/ % ' '");
    mostrar(0, 23, BACKGROUND_WHITE | FOREGROUND_RED,"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");

    mostrar(0, 9,  BACKGROUND_WHITE | FOREGROUND_RED," ####    ##   #    # ######     ####  #    # ###### #####  ");
    mostrar(0, 10, BACKGROUND_WHITE | FOREGROUND_RED,"#    #  #  #  ##  ## #         #    # #    # #      #    # ");
    mostrar(0, 11, BACKGROUND_WHITE | FOREGROUND_RED,"#      #    # # ## # #####     #    # #    # #####  #    # ");
    mostrar(0, 12, BACKGROUND_WHITE | FOREGROUND_RED,"#  ### ###### #    # #         #    # #    # #      #####  ");
    mostrar(0, 13, BACKGROUND_WHITE | FOREGROUND_RED,"#    # #    # #    # #         #    #  #  #  #      #   #  ");
    mostrar(0, 14, BACKGROUND_WHITE | FOREGROUND_RED," ####  #    # #    # ######     ####    ##   ###### #    # ");

    mostrar(0,6, BACKGROUND_WHITE | FOREGROUND_GREEN, "Geez, you've almost made it pal.. Try Again? (ESC)");

    mostrar(0,8, BACKGROUND_WHITE | FOREGROUND_GREEN, "Points: ");
    mostrar(7,8, BACKGROUND_WHITE | FOREGROUND_GREEN, points_str);

}



void GameManager::showLanding()
{
	unsigned int points = scene.getPoints();
	char points_str[7] = "";
	sprintf(points_str, "%06d", points);
    clrscr(BACKGROUND_WHITE);

    mostrar(3, 6, BACKGROUND_WHITE | FOREGROUND_RED,"                                   _              ");
    mostrar(3, 7, BACKGROUND_WHITE | FOREGROUND_RED,"                                 / | \\           ");
    mostrar(3, 8, BACKGROUND_WHITE | FOREGROUND_RED,"                                /  |  \\          ");
    mostrar(3, 9, BACKGROUND_WHITE | FOREGROUND_RED,"                               /       \\         ");
    mostrar(3, 10,BACKGROUND_WHITE | FOREGROUND_RED,"                              /    |    \\        ");
    mostrar(3, 11,BACKGROUND_WHITE | FOREGROUND_RED,"                                _/___\\_          ");
    mostrar(3, 12,BACKGROUND_WHITE | FOREGROUND_RED,"                          _______[o0o]_______     ");
    mostrar(3, 13,BACKGROUND_WHITE | FOREGROUND_RED,"                                O  O  O           ");
    mostrar(3, 14,BACKGROUND_WHITE | FOREGROUND_RED,"                          /        |        \\    ");
    mostrar(3, 15,BACKGROUND_WHITE | FOREGROUND_RED,"                         /___________________\\   ");
    mostrar(3, 16,BACKGROUND_WHITE | FOREGROUND_RED,"                        /          |          \\  ");
    mostrar(3, 17,BACKGROUND_WHITE | FOREGROUND_RED,"                       /          _|_          \\ ");
    mostrar(3, 18,BACKGROUND_WHITE | FOREGROUND_RED,"                      /                         \\");
    mostrar(3, 19,BACKGROUND_WHITE | FOREGROUND_RED,"                                                   ");
    mostrar(3, 20,BACKGROUND_WHITE | FOREGROUND_RED,"                                                   ");
    Sleep(300);

    mostrar(3, 6, BACKGROUND_WHITE | FOREGROUND_RED,"                                  ___             ");
    mostrar(3, 7, BACKGROUND_WHITE | FOREGROUND_RED,"                                 / | \\           ");
    mostrar(3, 8, BACKGROUND_WHITE | FOREGROUND_RED,"                                /  |  \\          ");
    mostrar(3, 9, BACKGROUND_WHITE | FOREGROUND_RED,"                               /       \\         ");
    mostrar(3, 10,BACKGROUND_WHITE | FOREGROUND_RED,"                              /    |    \\        ");
    mostrar(3, 11,BACKGROUND_WHITE | FOREGROUND_RED,"                             /           \\       ");
    mostrar(3, 12,BACKGROUND_WHITE | FOREGROUND_RED,"                            /      |      \\      ");
    mostrar(3, 13,BACKGROUND_WHITE | FOREGROUND_RED,"                           /               \\     ");
    mostrar(3, 14,BACKGROUND_WHITE | FOREGROUND_RED,"                          /        |        \\    ");
    mostrar(3, 15,BACKGROUND_WHITE | FOREGROUND_RED,"                         /___________________\\   ");
    mostrar(3, 16,BACKGROUND_WHITE | FOREGROUND_RED,"                        /          |          \\  ");
    mostrar(3, 17,BACKGROUND_WHITE | FOREGROUND_RED,"                       /          _|_          \\ ");
    mostrar(3, 18,BACKGROUND_WHITE | FOREGROUND_RED,"                      /      ____/___\\____      \\");
    mostrar(3, 19,BACKGROUND_WHITE | FOREGROUND_RED,"                      ___________[o0o]___________  ");
    mostrar(3, 20,BACKGROUND_WHITE | FOREGROUND_RED,"                               O   O    O          ");
    Sleep(300);
    mostrar(3, 6, BACKGROUND_WHITE | FOREGROUND_RED,"                                  ___             ");
    mostrar(3, 7, BACKGROUND_WHITE | FOREGROUND_RED,"                                 _/_\\_           ");
    mostrar(3, 8, BACKGROUND_WHITE | FOREGROUND_RED,"                               ___[o]___          ");
    mostrar(3, 9, BACKGROUND_WHITE | FOREGROUND_RED,"                                O  O  O           ");
    mostrar(3, 10,BACKGROUND_WHITE | FOREGROUND_RED,"                              /    |    \\        ");
    mostrar(3, 11,BACKGROUND_WHITE | FOREGROUND_RED,"                             /           \\       ");
    mostrar(3, 12,BACKGROUND_WHITE | FOREGROUND_RED,"                            /      |      \\      ");
    mostrar(3, 13,BACKGROUND_WHITE | FOREGROUND_RED,"                           /               \\     ");
    mostrar(3, 14,BACKGROUND_WHITE | FOREGROUND_RED,"                          /        |        \\    ");
    mostrar(3, 15,BACKGROUND_WHITE | FOREGROUND_RED,"                         /___________________\\   ");
    mostrar(3, 16,BACKGROUND_WHITE | FOREGROUND_RED,"                        /          |          \\  ");
    mostrar(3, 17,BACKGROUND_WHITE | FOREGROUND_RED,"                       /          _|_          \\ ");
    mostrar(3, 18,BACKGROUND_WHITE | FOREGROUND_RED,"                      /                         \\");
    mostrar(3, 19,BACKGROUND_WHITE | FOREGROUND_RED,"                                                   ");
    mostrar(3, 20,BACKGROUND_WHITE | FOREGROUND_RED,"                                                   ");

    srand(time(NULL));
    int i = rand() % 3;
    WORD foregrounds[] = {FOREGROUND_GREEN, FOREGROUND_RED, FOREGROUND_CYAN, FOREGROUND_INTENSITY };
    mostrar(7,0,BACKGROUND_WHITE | foregrounds[i],"#        ##   #    # #####  ###### ##### ");
    mostrar(7,1,BACKGROUND_WHITE | foregrounds[i],"#       #  #  ##   # #    # #      #    #");
    mostrar(7,2,BACKGROUND_WHITE | foregrounds[i],"#      #    # # #  # #    # #####  #    #");
    mostrar(7,3,BACKGROUND_WHITE | foregrounds[i],"#      ###### #  # # #    # #      #    #");
    mostrar(7,4,BACKGROUND_WHITE | foregrounds[i],"#      #    # #   ## #    # #      #    #");
    mostrar(7,5,BACKGROUND_WHITE | foregrounds[i],"###### #    # #    # #####  ###### ##### ");

    mostrar(0,6, BACKGROUND_WHITE | FOREGROUND_GREEN, "NICE WORK! YOU'VE MADE IT! Wanna try to beat your High Score? (ESC)");

    mostrar(0,8, BACKGROUND_WHITE | FOREGROUND_GREEN, "Points: ");
    mostrar(7,8, BACKGROUND_WHITE | FOREGROUND_GREEN, points_str);


}
