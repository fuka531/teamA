#include "Gameover.h"
#include"Title/Title.h"

Gameover::Gameover():Base(eType_Scene)
{
	m_img = COPY_RESOURCE("Gameover", CImage);
}

void Gameover::Update()
{
	if (PUSH(CInput::eButton10)) {
		SetKill();
		Base::Add(new Title());
	}
}

void Gameover::Draw()
{
	m_img.SetSize(1960, 1080);
	m_img.Draw();
}
