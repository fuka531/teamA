#include"Field.h"

Field::Field() :Base(eType_Field)
{
	m_img = COPY_RESOURCE("Ground", CImage);
	m_back = COPY_RESOURCE("Back", CImage);
	m_groundscroll = 0;
	m_ground_y = 1000;
}

void Field::Update()
{
	m_groundscroll += 1.3;
}

void Field::Draw()
{
	m_back.SetSize(1980, 1080);
	m_back.Draw();

	float sc;
	sc = m_groundscroll;
	m_img.SetSize(1920,1060);
	m_img.SetRect(sc, 0, sc + 500,250);
	m_img.Draw();
	
}
