#pragma once

//#include "Ressources.h"		// graphics management [and also for sounds in the future]

#include "stdafx.h"

class GameData
{


private:
	GameResources gameResources;

	VisMap mainMap;
public:
	GameData();
	~GameData();

	int init();

	GameResources* getResources();
};

