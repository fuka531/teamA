#pragma once
#include"Base/Base.h"

class Item :public Base {
private:
	CImage m_key;
public:
	Item();
	void Update();
	void Draw();
};