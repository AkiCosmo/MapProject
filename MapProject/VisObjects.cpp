#include "stdafx.h"



VisObjects::VisObjects()
{
}


VisObjects::~VisObjects()
{
	vector <GameObject*>::iterator it;
	for (it = objectList.begin(); it != objectList.end(); ++it) {
		if (*it) {
			delete *it;
		}
	}

}

int VisObjects::init(GameData* gameData) {
	
	int iRet = RET_OKAY;

	ResGraphic* graphic = gameData->getResources()->getGraphic(RESG_FIG_PEASANT1);

	ObjectMovable* tmpObject = new ObjectMovable();

	tmpObject->setGraphic(graphic);
	tmpObject->setPos(325, 480);

	objectList.push_back(tmpObject);

	return iRet;
}

void VisObjects::draw(GameData* gameData) {

	ResGraphic* graphic = NULL;
	vector <GameObject*>::iterator it;
	long posX, posY;

	fprintf(stderr, " object count: %d \n", objectList.capacity());


	for (it = objectList.begin(); it != objectList.end(); ++it) {
		//if (*it) {
		//*it.;
		graphic = gameData->getResources()->getGraphic(RESG_FIG_PEASANT1);
			(*it)->getGraphic();
			(*it)->getPos(posX, posY);
			al_draw_bitmap(graphic->getImage(RESG_IMG_STYLE_STD), posX, posY, 0);


			//}
	}


}
