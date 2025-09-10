#pragma once
#include"Base/Base.h"

class Title :public Base {
private:
	CImage m_title;
	int m_cnt;
	int m_move_cnt;
public:
	Title();
	void Update();
	void Draw();
};