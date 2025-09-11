#include "Goal.h"

Goal::Goal(const CVector2D& pos):Base(eType_Goal)
{
	m_pos = pos;
	m_goal = COPY_RESOURCE("Goal", CImage);
	m_goal.SetCenter(330/2,291/2);
	m_rect = CRect(300,-150,630,150);
}

void Goal::Update()
{
	const float move_speed = 1.9;
	m_pos.x += -move_speed;
}

void Goal::Draw()
{
	m_goal.SetSize(110*3,97*3);
	m_goal.SetPos(m_pos);
	m_goal.Draw();

	//DrawRect();
}

void Goal::Collision(Base* b)
{

}
