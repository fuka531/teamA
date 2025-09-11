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
	m_clear.SetPos(700,300);
	m_clear.SetSize(550,512);
	m_clear.Draw();
}
