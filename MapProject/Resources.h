#pragma once

#include "stdafx.h"

class GameResources
{
protected:
	vector <ResGraphic*> m_graphics;

	ALLEGRO_FONT *m_fontStd;

public:
	GameResources(void);
	~GameResources(void);

	int initResources(void);
	void clearResources(void);

	int loadImage(string& filename, int imageID);

	ResGraphic* getGraphic(int imageID);

	ALLEGRO_FONT* getFont(int fontID);
};


