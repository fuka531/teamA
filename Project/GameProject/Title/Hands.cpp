#include "Hands.h"
#include"Title.h"

Hands::Hands(const CVector2D& pos) :Base(eType_Scene)
{
	m_pos = pos;
	m_hands = COPY_RESOURCE("Hands", CImage);
}

void Hands::Update()
{
}

void Hands::Draw()
{
	m_hands.SetPos(m_pos);
	m_hands.Draw();
}
