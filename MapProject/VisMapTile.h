#pragma once

#include "VisMapTileBase.h"

class VisMapTile: public GameObject
{
protected:

	long index;
	//long m_idX, m_idY;

	bool activeStat;

	bool isWalkable;

	//ResGraphic *m_graphic;

	int mapPosLine;
	int mapPosCol;

public:
	VisMapTile();
	VisMapTile(ResGraphic* graphic, int line, int column, long index);
	~VisMapTile();

	//void setGraphic(ResGraphic* graphic);
	void setWalkable(bool walkable);

	//bool isClickable(void);

	//ALLEGRO_BITMAP* getImage(int style);

	ResGraphic* getGraphic(void);

	void setMapPos(int line, int column);
	void getMapPos(int &line, int &column);

};

