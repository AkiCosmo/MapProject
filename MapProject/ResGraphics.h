#pragma once

#include "stdafx.h"

class ResGraphic
{

protected:
	ALLEGRO_BITMAP	*m_image;
	int m_imageCode;

public:
	ResGraphic(void);
	~ResGraphic(void);

	void setImage(ALLEGRO_BITMAP* image);
	ALLEGRO_BITMAP* getImage(int style);

	void clear(void);

	void setCode(int imageCode);
	int getCode(void);

};

