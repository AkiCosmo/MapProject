//#include "Visuals.h"
#include "stdafx.h"

Visuals::Visuals()
{
	Display = NULL;
}


Visuals::~Visuals()
{
	if (Display) {
		al_destroy_display(Display);
	}
}


int Visuals::init(Gamebase* gamebase, GameData* gameData)
{
	Display = al_create_display(1000, 700);
	if (!Display) {
		return RET_ERR;
	}
	GameMap.initMap(gameData);

	return 0;
}

ALLEGRO_DISPLAY* Visuals::getDisplay(void)
{
	return Display;
}

int Visuals::draw(GameData* gameData)
{
	ResGraphic* graphic = NULL;

	al_set_target_bitmap(al_get_backbuffer(Display)); // set backbuffer als drawing place

	al_clear_to_color(al_map_rgb(0, 0, 0)); // and make it black

	// draw all visual elements in right order

	//draw map
	GameMap.draw(getDisplay(), gameData);

	// draw objects
	gameData->getgameObjects()->draw(gameData);


	al_flip_display(); // ready to show

	return 0;
}
