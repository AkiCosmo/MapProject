
#include "stdafx.h"

//#include "ResGraphics.h"


ResGraphic::ResGraphic(void)
{
	m_imageCode = 0;
}


ResGraphic::~ResGraphic(void)
{
}

void ResGraphic::setImage(ALLEGRO_BITMAP* image)
{
	if (image) {
		m_image = image;
	}
}

ALLEGRO_BITMAP* ResGraphic::getImage(int style)
{
	ALLEGRO_BITMAP* retBitmap = NULL;

	switch (style) {
	case RESG_IMG_STYLE_STD:
		retBitmap = m_image;
	}

	return retBitmap;
}

void ResGraphic::clear(void)
{
	if (m_image) {
		al_destroy_bitmap(m_image);	
	}

}

void ResGraphic::setCode(int imageCode)
{
	if (imageCode >0) {
		m_imageCode = imageCode;
	}
}

int ResGraphic::getCode(void)
{
	return m_imageCode;
}
