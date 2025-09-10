#include "Game.h"
#include "Field.h"
#include "Item.h"
#include "Goal.h"

Game::Game():Base(eType_Scene)
{
	Base::Add(new Field());
	Base::Add(new Item());
	Base::Add(new Goal(CVector2D(2000,700)));
}

void Game::Update()
{

}
