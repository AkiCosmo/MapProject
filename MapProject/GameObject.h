#pragma once


class GameObject
{
protected:

	ResGraphic *m_graphic;

	bool m_isClickable;
	bool m_isVisible;

	long m_posX, m_posY;	// the position, the object should be drawn on
	long m_posXMiddle, m_posYMiddle;	// the position, the object schoud be moved on


public:
	GameObject();
	virtual ~GameObject();

	bool getClickable(void);
	ResGraphic* getGraphic();

	void setPos(long posX, long posY);
	void getPos(long &posX, long &posY);

	void setGraphic(ResGraphic* graphic);
	
};

