#include "Clear.h"
#include"Title/Title.h"

Clear::Clear():Base(eType_Clear)
{
	m_clear = COPY_RESOURCE("Clear", CImage);
}

void Clear::Update()
{
	if (PUSH(CInput::eButton10)) {
		SetKill();
		Base::Add(new Title());
	}
}

void Clear::Draw()
{
	m_clear.SetPos(0,0);
	m_clear.SetSize(1980,1080);
	m_clear.Draw();
}
