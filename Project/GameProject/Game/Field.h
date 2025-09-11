#pragma once
#include"Base/Base.h"

class Field :public Base
{
private:
	CImage m_img;
	CImage m_back;
	float m_groundscroll;
	float m_cnt;
	float m_ground_y;
public:
	Field();
	void Update();
	void Draw();

	float GetGroundY() {
		return m_ground_y;
	}
};
