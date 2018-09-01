//#include "Ressources.h"
#include "stdafx.h"

GameResources::GameResources()
{
}


GameResources::~GameResources()
{
}

void GameResources::clearResources(void)
{
	// free all CResGraphics and their bitmaps
	ALLEGRO_BITMAP* tBitmap = NULL;

	vector <ResGraphic*>::iterator it;
	for (it = m_graphics.begin(); it != m_graphics.end(); ++it) {
		if (*it) {
			((ResGraphic*)*it)->clear();
			delete *it;
		}
	}
}

int GameResources::initResources(void) {

	// load all graphics

	string str;
	//al_set_new_bitmap_flags(ALLEGRO_VIDEO_BITMAP);
	//al_set_new_bitmap_flags(

	str = "TileGreen32.png";
	loadImage(str, RESG_MAPTILE);

	
	str = "TileGreenWayNS32.png";
	loadImage(str, RESG_MAPTILE_WAYNS);

	str = "TileGreenWayWO32.png";
	loadImage(str, RESG_MAPTILE_WAYWO);

	str = "Icon_Bauer32.png";
	loadImage(str, RESG_FIG_PEASANT1);

	//str = "ActiveFrame.png";
	//loadImage(str, RESG_MAPTILEACTIVE);

	//str = "worker-blue-th2t.png";
	//loadImage(str, RESG_PLAYERSTD);

	ALLEGRO_PATH *path = al_get_standard_path(ALLEGRO_RESOURCES_PATH);
	al_set_path_filename(path, "DejaVuSans.ttf");
	fprintf(stderr, al_path_cstr(path, ALLEGRO_NATIVE_PATH_SEP));
	fprintf(stderr, "\n");
	m_fontStd = al_load_ttf_font(al_path_cstr(path, ALLEGRO_NATIVE_PATH_SEP), 12, 0);
	al_destroy_path(path);

	if (!m_fontStd) {
		ostringstream errTxt;
		errTxt << "Error: Resource::initResource - Error loading DejaVuSans.ttf" << "\n";
		fprintf(stderr, errTxt.str().c_str());
		return RET_ERR;
	}
	return RET_OKAY;
}

int GameResources::loadImage(string& filename, int imageID)
{
	ALLEGRO_BITMAP* bitmap = NULL;
	ResGraphic* graphic = NULL;
	ostringstream dbgTxt;

	graphic = new ResGraphic();
	if (!graphic)
		return RET_ERR;

	ALLEGRO_PATH *path = al_get_standard_path(ALLEGRO_RESOURCES_PATH);
	al_drop_path_tail(path);
	al_append_path_component(path, RES_PATH_ADDITION);

#ifdef _DEBUG
	dbgTxt << "Resourcepath: " << al_path_cstr(path, ALLEGRO_NATIVE_PATH_SEP) << "\n";
	log_msg(&dbgTxt);
#endif

	al_set_path_filename(path, filename.c_str());
	bitmap = al_load_bitmap(al_path_cstr(path, ALLEGRO_NATIVE_PATH_SEP));
	al_destroy_path(path);

	if (!bitmap) {
		ostringstream errTxt;
		errTxt << "Error: Resource::loadImage - Error loading " << filename << "\n";
		fprintf(stderr, errTxt.str().c_str());
		return RET_ERR;
	}

	graphic->setImage(bitmap);
	graphic->setCode(imageID);
	m_graphics.push_back(graphic);
	fprintf(stderr, " -> success\n");
	return RET_OKAY;
}

ResGraphic* GameResources::getGraphic(int imageID)
{
	ResGraphic* graphic = NULL;
	unsigned int id;

	//	vector <CResGraphic*>::iterator it;
	//	for (it = m_graphics.begin() ; it != m_graphics.end(); ++it) {
	//		if (*it) {
	//			if (((CResGraphic*)*it)->getCode() == imageID) {
	//				graphic = *it;
	//			}
	//		}
	//	}
	id = imageID;
	if (id < m_graphics.size()) {
		graphic = m_graphics[imageID];
	}
	return graphic;
}


ALLEGRO_FONT* GameResources::getFont(int fontID)
{
	ALLEGRO_FONT* retFont = NULL;

	switch (fontID) {
	case RESFONT_STD:
		retFont = m_fontStd;
	}

	return retFont;
}
