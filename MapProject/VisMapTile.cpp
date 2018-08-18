//#include "VisMapTileBase.h"
//#include "VisMapTile.h"
#include "stdafx.h"

VisMapTile::VisMapTile()
{
}

VisMapTile::VisMapTile(ResGraphic* graphic, int line, int column, long index)
{
	if (graphic) {
		graphic = graphic;
		mapPosLine = line;
		mapPosCol = column;
		index = index;
	}
}



VisMapTile::~VisMapTile()
{
}
void VisMapTile::setImage(ResGraphic* graphic)
{
	if (graphic) {
		graphic = graphic;
	}
}


ALLEGRO_BITMAP* VisMapTile::getImage(void)
{

	//	if (m_active) {
	//		return m_imageActive;
	//	}
	//	else {
	//		return m_image;
	return (graphic->getImage(RESG_IMG_STYLE_STD));
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