#include "Game.h"
#include "Field.h"
#include "Item.h"
#include "Goal.h"
#include "Enemy.h"
#include "Player.h"
#include "object.h"

Game::Game() :Base(eType_Scene)
{
	Base::Add(new Field());
	Base::Add(new Item());
	Base::Add(new Goal(CVector2D(5000, 700)));
	Base::Add(new Player(CVector2D(300, 1000), false));
	m_cnt = 0;


	Base::Add(new Enemy(CVector2D(1200, 1000), true));
	Base::Add(new Enemy(CVector2D(1800, 1000), true));
	Base::Add(new Enemy(CVector2D(2400, 1000), true));

}
void Game::Update()
{
	m_cnt--;
	if (m_cnt <= 0) {
		Base::Add(new Object(CVector2D(m_scroll.x + SCREEN_WIDTH + 256, 850), true));
		m_cnt = rand() %  120 + 60;
	}
}
