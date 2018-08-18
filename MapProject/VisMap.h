#pragma once

#include "stdafx.h"

class VisMapTileBase;
class ResGraphic;
class GameData;

class VisMap
{
protected:
	vector <VisMapTile*> mapTileList;

	long tileCounter;							// how much tiles we have in the game map
  	//	vector <ALLEGRO_BITMAP *> m_mapGraphics;	// list of all map graphics (not used yet)

	long activeTileID;
	ResGraphic* activeTileGraphic;

	int tileWidth, tileHeight;

	ALLEGRO_BITMAP* map;

	int mapLines;
	int mapCols;

	int mapWith;
	int mapHight;


public:
	VisMap();
	~VisMap();

	void clearMap(void);
	int initMap(GameData* gameData);
	void addTile(ResGraphic* graphic, int posLine, int posCol, long posX, long posY);

	void draw(ALLEGRO_DISPLAY* display, GameData *gameData);
};

