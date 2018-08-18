#pragma once

#include "VisMapTileBase.h"

class VisMapTile: public GameObject
{
protected:

	long index;
	//long m_idX, m_idY;

	bool activeStat;

	bool walkable;

	ResGraphic *graphic;

	int mapPosLine;
	int mapPosCol;

public:
	VisMapTile();
	VisMapTile(ResGraphic* graphic, int line, int column, long index);
	~VisMapTile();

	void setImage(ResGraphic* graphic);
	bool isClickable(void);

	//ALLEGRO_BITMAP* getImage(int style);

	ALLEGRO_BITMAP* getImage(void);

	void setMapPos(int line, int column);
	void getMapPos(int &line, int &column);

};

