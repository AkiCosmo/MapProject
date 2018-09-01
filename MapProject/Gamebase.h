#pragma once

//#include "stdafx.h"

//class GameData;

class Gamebase
{
protected:
	GameData* gameData;

	ALLEGRO_EVENT_QUEUE *eventQueue;
	ALLEGRO_TIMER		*eventTimer;

	float gameFPS;

	Visuals gameVisuals; 


public:
	Gamebase();
	~Gamebase();
	
	int initFrameworks(void);
	int initResources(void);
	int init();
	GameData* getData();

	void gameLoop(void);

};

