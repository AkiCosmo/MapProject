//#include "VisMap.h"
#include "stdafx.h"



VisMap::VisMap()
{
	tileCounter = 0;			// every tile gets an ID

	m_tileWidth = 0;
	m_tileHeight = 0;

	drawXzero = 0;				// zero position for drawing
	drawYzero = 0;

	mapLines = 20;				// numer of lines in the map
	mapCols = 30;				// numer of columns in the map

	activeTileID = 0;
	activeTileGraphic = NULL;


	//mapTileList.reserve(mapLines * mapCols);	// line * cols = num tiles in the map -> allocate the whole vector memory at once

}


VisMap::~VisMap()
{
	// kills the tilemap and frees memory
	// vector <VisMapTile*>::iterator it;
	// for (it = mapTileList.begin(); it != mapTileList.end(); ++it) {
	//	if (*it) {
	//		delete *it;
	//	}
	//}

	clearMap();
}


void VisMap::clearMap(void) {

	int line = 0, col = 0;

	for (col = 0; col < mapCols; col++) {
		for (line = 0; line < mapLines; line++) {
			if (tileMap[line][col]) {
				delete tileMap[col][line];
			}
		}
	}
}

int VisMap::initMap(GameData* gameData) {

	int iRet = RET_OKAY;
	int line = 0, col = 0;
	long posX, posY;
	//long i, y;

	ResGraphic* graphic = NULL;
	VisMapTile *tmpTile = NULL;

	graphic = gameData->getResources()->getGraphic(RESG_MAPTILE);

	if (graphic->getImage(RESG_IMG_STYLE_STD)) {
		m_tileWidth = al_get_bitmap_width(graphic->getImage(RESG_IMG_STYLE_STD));
		m_tileHeight = al_get_bitmap_height(graphic->getImage(RESG_IMG_STYLE_STD));
	}
	else {
		return RET_ERR;
	}

	// zero the map
	// build a tile map
	if (iRet == RET_OKAY) {
		int line = 0, col = 0;
		for (col = 0; col < mapCols; col++) {
			for (line = 0; line < mapLines; line++) {
				tileMap[col][line] = NULL;
				posX = col * m_tileWidth;
				posY = line * m_tileHeight;
				addTile(graphic, line, col, posX, posY);	// hier müsste eigentlich eine MAP geladen werden, so sind alle MAP-Grafiken gleich
			}
		}
	}

	// setzen der Strasse
	
	graphic = gameData->getResources()->getGraphic(RESG_MAPTILE_WAYNS);

	for (line = 8; line < 15; line++) {
		//tmpTile = getTileFromPos(line, 10);
		tmpTile = tileMap[10][line];

		if (tmpTile) {
#ifdef _DEBUG
			ostringstream dbgTxt;
			//tmpTile->getMapPos(line, col);
			dbgTxt << "Tile to change. Line: " << line << ", Col: " << 10 << "\n";
			log_msg(&dbgTxt);
#endif
			tmpTile->setGraphic(graphic);
			tmpTile->setWalkable(true);
		}
	}

	//setActiveTile(0);

	fprintf(stderr, " init Map\t -> success\n");
	fprintf(stderr, " added %d tiles\n", tileCounter);


	return iRet;
}

VisMapTile* VisMap::addTile(ResGraphic* graphic, int posLine, int posCol, long posX, long posY)
{
	// ToDo: Allocation for the whole map at once

	VisMapTile *tile = new VisMapTile(graphic, posLine, posCol, tileCounter);

	// mapTileList.push_back(tile);
	tileMap[posCol][posLine] = tile;

	tileCounter++;

	return tile;

}

VisMapTile* VisMap::changeTile(ResGraphic* graphic, long tileID)
{
//	VisMapTile *tile = mapTileList[tileID];

//	if (tile) {
//		tile->setGraphic(graphic);
//	}

	return NULL;
}

VisMapTile* VisMap::getTileFromPos(int posLine, int posCol) {
/*
	int line, col;
	//VisMapTile* tmpTile = NULL;
	VisMapTile* foundTile = NULL;
	ostringstream dbgTxt;

	vector <VisMapTile*>::iterator itTile;
//	for (it = mapTileList.begin(); it != mapTileList.end(); ++it) {
	for (itTile = mapTileList.begin(); itTile != mapTileList.end(); ++itTile) {
		//ostringstream ostr;
		if (*itTile) {

			(*itTile)->getMapPos(line, col);
			if (line == posLine && col == posCol) {
#ifdef _DEBUG
				dbgTxt << "Tile found. Line: " << line << ", Col: " << col << "\n";
				log_msg(&dbgTxt);
#endif
				foundTile = (*itTile);
				break;
			}
		}
	}

	return foundTile;
	*/
	return NULL;
}

void VisMap::draw(ALLEGRO_DISPLAY* display, GameData *gameData) {

	ALLEGRO_BITMAP* image = NULL;
	ResGraphic* graphic = NULL;
	int xTilePos, yTilePos;
	int line, col;
	//int width, height;
	ALLEGRO_FONT* font = NULL;

	// draw all map tiles as map background
	vector <VisMapTile*>::iterator itTile;
	VisMapTile* tile = NULL;

	// draw map
	//width =  al_get_bitmap_width(image);
	//height =  al_get_bitmap_height(image);
	//font = gameData->getFont(RESFONT_STD);
	ALLEGRO_COLOR color = al_map_rgb(255, 255, 255);
	al_set_target_bitmap(al_get_backbuffer(display));

	for (col = 0; col < mapCols; col++) {
		for (line = 0; line < mapLines; line++) {

//	for (itTile = mapTileList.begin(); itTile != mapTileList.end(); ++itTile) {
		//ostringstream ostr;
		//if (tile = *itTile) {

			if (tile = tileMap[col][line]) {

				//image = tile->getImage();	// eigentlich richtig, wenn die Tiles unterschiedlich sind
				//tile->getMapPos(line, col);
				xTilePos = m_tileWidth * col;
				yTilePos = m_tileHeight * line;
				graphic = tile->getGraphic();
				//al_draw_bitmap(image, tile->getPosX(), tile->getPosY(), 0);
				al_draw_bitmap(graphic->getImage(RESG_IMG_STYLE_STD), xTilePos, yTilePos, 0);

				//ostr << "[" << tile->m_mapX << "," << tile->m_mapY << "]";
				//al_draw_text(font, color, tile->getPosX() + 45, tile->getPosY() + 45, ALLEGRO_ALIGN_CENTRE, ostr.str().c_str());
			}
		}
	}

	// draw objects

	//vector <CGObject*>::iterator itObj;

	//for (itObj = gameData->getGameObjects()->getGameObjectList()->begin(); itObj != gameData->getGameObjects()->getGameObjectList()->end(); ++itObj) {
	//	if (*itObj) {
	//		image = (*itObj)->getImage();
	//		al_draw_bitmap(image, (*itObj)->getPosX(), (*itObj)->getPosY(), 0);
	//	}
	//}

	// mark selected tile 
	//image = m_activeGraphic->getImage(RESG_IMG_STYLE_STD);
	//al_draw_bitmap(image, m_mapTiles[m_activeTileID]->getPosX(), m_mapTiles[m_activeTileID]->getPosY(), 0);

	// draw menu
	// a) use menu icons
	// b) catch mouse
	// c) show menu popup
	// d) select build tile and place it on the map
}