#include "Title.h"
#include"Game/Game.h"
#include"Hands.h"

Title::Title():Base(eType_Scene)
{
	m_title = COPY_RESOURCE("Title", CImage);
	m_cnt = 0;
	m_move_cnt = 0;
}

void Title::Update()
{
	if (m_cnt++ > 60 && PUSH(CInput::eButton10)) {
		KillAll();
		Base::Add(new Game());
	}

	m_move_cnt++;
	if (m_move_cnt == 120){
		Base::Add(new Hands(CVector2D(100, 300)));
	}
	if (m_move_cnt == 240) {
		Base::Add(new Hands(CVector2D(1000, 600)));
	}
	if (m_move_cnt == 300) {
		Base::Add(new Hands(CVector2D(1500,200)));
	}


}

void Title::Draw()
{
	m_title.SetSize(1960, 1080);
	m_title.Draw();
}
