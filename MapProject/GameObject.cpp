//#include "Object.h"

#include "stdafx.h"

GameObject::GameObject()
{
	m_isClickable = false;
	m_isVisible = true;

	m_graphic = NULL;

	m_posX = m_posY = 0;	// the position, the object should be drawn on
}


GameObject::~GameObject()
{
}

bool GameObject::getClickable(void)
{
	return m_isClickable;
}

ResGraphic* GameObject::getGraphic() {

	return m_graphic;
}

void GameObject::setPos(long posX, long posY) 
{

	if (posX && posY >= 0) {
		m_posX = posX;
		m_posY = posY;
	}
}

void GameObject::getPos(long &posX, long &posY)
{
	posX = m_posX;
	posY = m_posY;
}

void GameObject::setGraphic(ResGraphic* graphic)
{
	if (graphic) {
		m_graphic = graphic;
	}
}
