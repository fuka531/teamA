#pragma once
#include"Base/Base.h"

class Item :public Base {
private:
	CImage m_key;
public:
	Item(const CVector2D& pos);
	void Update();
	void Draw();
	void Collision(Base* b);
};