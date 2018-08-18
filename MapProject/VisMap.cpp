//#include "VisMap.h"
#include "stdafx.h"



VisMap::VisMap()
{
	tileCounter = 0;			// every tile gets an ID

	tileWidth = 0;
	tileHeight = 0;

	mapLines = 30;				// numer of lines in the map
	mapCols = 20;				// numer of columns in the map

	activeTileID = 0;
	activeTileGraphic = NULL;


	mapTileList.reserve(mapLines * mapCols);	// line * cols = num tiles in the map -> allocate the whole vector memory at once

}


VisMap::~VisMap()
{
	// kills the tilemap and frees memory
	vector <VisMapTile*>::iterator it;
	for (it = mapTileList.begin(); it != mapTileList.end(); ++it) {
		if (*it) {
			delete *it;
		}
	}
}

void VisMap::clearMap(void) {

	// kills the tilemap and frees memory
	vector <VisMapTile*>::iterator it;
	for (it = mapTileList.begin(); it != mapTileList.end(); ++it) {
		if (*it) {
			delete *it;
		}
	}
}

int VisMap::initMap(GameData* gameData) {

	int iRet = RET_OKAY;
	int line = 0, col = 0;
	long posX, posY;

	ResGraphic* graphic = NULL;

	graphic = gameData->getResources()->getGraphic(RESG_MAPTILE);

	if (graphic->getImage(RESG_IMG_STYLE_STD)) {
		tileWidth = al_get_bitmap_width(graphic->getImage(RESG_IMG_STYLE_STD));
		tileHeight = al_get_bitmap_height(graphic->getImage(RESG_IMG_STYLE_STD));
	}
	else {
		return RET_ERR;
	}

	//m_activeGraphic = gameData->getResources()->getGraphic(RESG_MAPTILEACTIVE);


	// load tile graphic and build a tile map
	if (iRet == RET_OKAY) {
		for (line = 0; line < mapLines; line++) {
			for (col = 0; col < mapCols; col++) {
				posX = col * tileWidth;
				posY = line * tileHeight;
				addTile(graphic, line, col, posX, posY);	// hier müsste eigentlich eine MAP geladen werden, so sind alle MAP-Grafiken gleich
			}
		}
	}

	//setActiveTile(0);

	fprintf(stderr, " init Map\n -> success\n");
	fprintf(stderr, " added %d tiles", tileCounter);


	return iRet;
}

void VisMap::addTile(ResGraphic* graphic, int posLine, int posCol, long posX, long posY)
{
	VisMapTile *tile = new VisMapTile(graphic, posLine, posCol, tileCounter);
	tileCounter++;

	//tile->setGraphic(graphic);

	//	tile->setMapPos(posX, posY);
	//tile->setPos(posCol, posLine, posX, posY);

	//tile->m_index = m_tileCounter;
	//m_tileCounter++;

	mapTileList.push_back(tile);

}

void VisMap::draw(ALLEGRO_DISPLAY* display, GameData *gameData) {

	ALLEGRO_BITMAP* image = NULL;
	int xTilePos, yTilePos;
	int line, col;
	int width, height;
	ALLEGRO_FONT* font = NULL;

	// draw all map tiles as map background
	vector <VisMapTile*>::iterator itTile;
	VisMapTile* tile = NULL;

	// draw map
	image = gameData->getResources()->getGraphic(RESG_MAPTILE)->getImage(RESG_IMG_STYLE_STD);
	width =  al_get_bitmap_width(image);
	height =  al_get_bitmap_height(image);
	//font = gameData->getFont(RESFONT_STD);
	ALLEGRO_COLOR color = al_map_rgb(255, 255, 255);
	al_set_target_bitmap(al_get_backbuffer(display));

	for (itTile = mapTileList.begin(); itTile != mapTileList.end(); ++itTile) {
		//ostringstream ostr;
		if (tile = *itTile) {

			//image = tile->getImage();	// eigentlich richtig, wenn die Tiles unterschiedlich sind
			tile->getMapPos(line, col);
			xTilePos = width * line;
			yTilePos = height * col;
			//al_draw_bitmap(image, tile->getPosX(), tile->getPosY(), 0);
			al_draw_bitmap(image, xTilePos, yTilePos, 0);
			//ostr << "[" << tile->m_mapX << "," << tile->m_mapY << "]";
			//al_draw_text(font, color, tile->getPosX() + 45, tile->getPosY() + 45, ALLEGRO_ALIGN_CENTRE, ostr.str().c_str());
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