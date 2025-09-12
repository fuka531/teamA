#pragma once
#include "../Base/Base.h"

class Player : public Base {
private:
	//アニメーションの種類
	enum {
		eAnimIdle,
		eAnimJump
	};

	CImage m_img;
	bool   m_flip;
	//着地フラグ
	bool m_is_ground;
	bool m_haskey;
	float m_move_speed = 5;

	//状態
	enum {
		eState_Idle,
		eState_Jump,
	};

	//状態変数
	int m_state;
	//各状態での挙動
	void StateIdle();
	void StateJump();
public:
	Player(const CVector2D& pos,bool flip);
	void Update();
	void Draw();
	void Collision(Base* b);

	static TexAnimData _anim_data[];
};
