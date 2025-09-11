#pragma once
#include "../Base/Base.h"

class Object :public Base {

private:
	CImage m_img;
	bool   m_flip;

public:
	Object(const CVector2D& pos, bool flip);
	void Update();
	void Draw();
	void Collision(Base* b);
};