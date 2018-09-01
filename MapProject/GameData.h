#pragma once

#include "stdafx.h"

class GameData
{


private:
	GameResources gameResources;

	VisObjects gameObjects;

protected:
	int initObjectList();

public:
	GameData();
	~GameData();

	int init();
	VisObjects* getgameObjects();

	GameResources* getResources();

};

