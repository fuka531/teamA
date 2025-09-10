#include "Clear.h"

Clear::Clear():Base(eType_Clear)
{
	m_clear = COPY_RESOURCE("Clear", CImage);
}

void Clear::Update()
{
}

void Clear::Draw()
{
	m_clear.SetPos(700,300);
	m_clear.SetSize(550,512);
	m_clear.Draw();
}
