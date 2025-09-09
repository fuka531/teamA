#include "Item.h"

Item::Item():Base(eType_Item)
{
	m_key = COPY_RESOURCE("Key", CImage);
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
	m_key.SetPos(0,0);
	m_key.SetSize(100,100);
	m_key.Draw();
}

void Item::Collsion(Base* b)
{
}
