//#include "VisMapTileBase.h"
//#include "VisMapTile.h"
#include "stdafx.h"

VisMapTile::VisMapTile()
{
	m_graphic = NULL;
}

VisMapTile::VisMapTile(ResGraphic* graphic, int line, int column, long index)
{
	if (graphic) {
		m_graphic = graphic;
		mapPosLine = line;
		mapPosCol = column;
		index = index;

		isWalkable = false;
	}
}



VisMapTile::~VisMapTile()
{
}

void VisMapTile::setWalkable(bool walkable)
{
	isWalkable = walkable;
}


ResGraphic* VisMapTile::getGraphic()
{

	//	if (m_active) {
	//		return m_imageActive;
	//	}
	//	else {
	//		return m_image;
	return m_graphic;
	//	}
}


void VisMapTile::setMapPos(int line, int column) {
	mapPosLine = line;
	mapPosCol = column;

	//	m_idX = column;
	//	m_idY = line;
}

void VisMapTile::getMapPos(int &line, int &column) {
	line = mapPosLine;
	column = mapPosCol;
}

