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
	int iRet = RET_OKAY;

	if (!gameResources.initResources()) {
		return RET_ERR;
	}

	if (!initObjectList()) {
		return RET_ERR;
	}

	return iRet;
}

GameResources* GameData::getResources() {
	return &gameResources;
}

int GameData::initObjectList() {
	int iRet = RET_OKAY;

	gameObjects.init(this);
	// create all game objects until we get them from resource file
	// at first we crate a peasant as a test figure and move him aroud

	return iRet;
}

VisObjects* GameData::getgameObjects() {

	return &gameObjects;
}