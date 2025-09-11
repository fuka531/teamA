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
	m_clear.SetPos(0,0);
	m_clear.SetSize(1980,1080);
	m_clear.Draw();
}
