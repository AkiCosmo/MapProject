#pragma once

#include "stdafx.h"

class Gamebase;
class VisGameWindow;
class VisMap;
class GameData;

class Visuals
{
private:
	VisGameWindow GameWindow(void);
	ALLEGRO_DISPLAY *Display;
	VisMap GameMap;


public:
	Visuals();
	~Visuals();
	int init(Gamebase* gamebase, GameData* gameData);
	int draw(GameData* gameData);

	ALLEGRO_DISPLAY* getDisplay(void);

};

