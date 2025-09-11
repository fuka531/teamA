#include "Item.h"

Item::Item(const CVector2D& pos):Base(eType_Item)
{
	m_key = COPY_RESOURCE("Key", CImage);
	m_pos = pos;
	m_key.SetCenter(50, 100);
	m_rect = CRect(-50, -100, 50, 10);
}

void Item::Update()
{
	if (PUSH(CInput::eButton1))
	{
		SetKill();
	}
}

void Item::Draw()
{
	m_key.SetPos(GetScreenPos(m_pos));
	m_key.SetSize(100,100);
	m_key.Draw();
	DrawRect();
}

void Item::Collision(Base* b)
{
}
