#pragma once
#include"Base/Base.h"

class Hands :public Base {
private:
	CImage m_hands;
public:
	Hands(const CVector2D& pos);
	void Update();
	void Draw();

};