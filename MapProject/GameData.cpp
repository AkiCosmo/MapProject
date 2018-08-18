//#include "Data.h"

#include "stdafx.h"


GameData::GameData()
{
}


GameData::~GameData()
{
	gameResources.clearResources();
}


int GameData::init()
{
	gameResources.initResources();

	return 0;
}

GameResources* GameData::getResources() {
	return &gameResources;
}
