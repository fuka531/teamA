#pragma once
#include"Base/Base.h"

class Field :public Base
{
private:
	CImage m_img;
	CImage m_back;
	float m_groundscroll;
public:
	Field();
	void Update();
	void Draw();
};
