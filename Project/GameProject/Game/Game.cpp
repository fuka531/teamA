#include "Game.h"
#include "Field.h"
#include "Item.h"
#include "Goal.h"
#include "Enemy.h"
#include "Player.h"

Game::Game():Base(eType_Scene)
{
	Base::Add(new Field());
	Base::Add(new Item());
	Base::Add(new Goal(CVector2D(2000,700)));

	Base::Add(new Enemy(CVector2D(1500, 1000), true));
	Base::Add(new Player(CVector2D(300, 1000), false));
}

void Game::Update()
{

}
