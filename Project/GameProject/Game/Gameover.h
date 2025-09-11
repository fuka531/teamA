#pragma once
#include"Base/Base.h"

class Gameover :public Base {
private:
	CImage m_img;
public:
	Gameover();
	void Update();
	void Draw();
};