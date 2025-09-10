#pragma once
#include "../Base/Base.h"

class Enemy :public Base {

private:
    enum {
        eState_Idle,
        eState_Attack,
        eState_Damage,
        eState_Down,
        eAnimIdle = 0,
        eAnimRun,
        eAnimJumpUp,
        eAnimJumpDown,
        eAnimAttack01,
        eAnimDamage,
        eAnimDown,
    };

    int m_state;
        
	CImage m_img;
	bool m_flip;
	bool m_is_ground;
    int m_hp;   

public:
    Enemy(const CVector2D& pos, bool flip);
    void Update();
    void Draw();
    void Collision(Base* b);

    void StateIdle();
    void StateDamage();
    void StateDown();

};