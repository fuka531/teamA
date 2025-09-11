#pragma once
#include "../Base/Base.h"

class Player : public Base {
private:
	//アニメーションの種類
	enum {
		eAnimIdle,
	};

	CImage m_img;
	bool   m_flip;
	//着地フラグ
	bool m_is_ground;

	//状態
	enum {
		eState_Idle,
	};

	//状態変数
	int m_state;
	//各状態での挙動
	void StateIdle();
public:
	Player(const CVector2D& pos,bool flip);
	void Update();
	void Draw();
	void Collision(Base* b);

	static TexAnimData _anim_data[];
};
