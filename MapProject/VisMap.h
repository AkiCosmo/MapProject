#pragma once

#include "stdafx.h"

//class VisMapTileBase;
class ResGraphic;
class GameData;

class VisMap
{
protected:
	// vector <VisMapTile*> mapTileList;

	VisMapTile* tileMap[30][20];

	long tileCounter;							// how much tiles we have in the game map
  	//	vector <ALLEGRO_BITMAP *> m_mapGraphics;	// list of all map graphics (not used yet)

	long activeTileID;
	ResGraphic* activeTileGraphic;

	int m_tileWidth, m_tileHeight;

	ALLEGRO_BITMAP* map;

	int mapLines;
	int mapCols;

	int mapWith;
	int mapHight;

	long drawXzero;		// zero position für drawing due to scrolling around the map over the edges
	long drawYzero;


public:
	VisMap();
	~VisMap();

	void clearMap(void);
	int initMap(GameData* gameData);
	VisMapTile* addTile(ResGraphic* graphic, int posLine, int posCol, long posX, long posY);
	VisMapTile* changeTile(ResGraphic* graphic, long tileID);
	VisMapTile* getTileFromPos(int posLine, int posCol);

	void draw(ALLEGRO_DISPLAY* display, GameData *gameData);
};

