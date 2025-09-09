#include "Item.h"

Item::Item():Base(eType_Item)
{
	m_key = COPY_RESOURCE("Key", CImage);
}

void Item::Update()
{
}

void Item::Draw()
{
	m_key.SetPos(0,0);
	m_key.Draw();
}
