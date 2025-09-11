#pragma once
#include "../Base/Base.h"

class Enemy :public Base {

private:
    enum {
        eAnimIdle = 0,
    };

    int m_state;
        
	CImage m_img;
	bool m_flip;
	bool m_is_ground;

public:
    Enemy(const CVector2D& pos, bool flip);
    void Update();
    void Draw();
    void Collision(Base* b);

    static TexAnimData _anim_data[];
};