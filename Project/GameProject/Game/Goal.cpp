#include "Goal.h"

Goal::Goal(const CVector2D& pos):Base(eType_Goal)
{
	m_pos = pos;
	m_goal = COPY_RESOURCE("Goal", CImage);
	m_goal.SetCenter(330/2,291/2);
	m_rect = CRect(-160,-150,200,200);
}

void Goal::Update()
{
}

void Goal::Draw()
{
	m_goal.SetSize(110*3.5,97*3.5);
	m_goal.SetPos(GetScreenPos(m_pos));
	m_goal.Draw();

	DrawRect();
}

void Goal::Collision(Base* b)
{

}
