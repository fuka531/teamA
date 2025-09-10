#pragma once
#include"Base/Base.h"

class Clear :public Base {
private:
	CImage m_clear;
public:
	Clear();
	void Update();
	void Draw();
};