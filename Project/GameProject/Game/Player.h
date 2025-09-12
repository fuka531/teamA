#pragma once
#include "../Base/Base.h"

class Player : public Base {
private:
	//�A�j���[�V�����̎��
	enum {
		eAnimIdle,
		eAnimJump
	};

	CImage m_img;
	bool   m_flip;
	//���n�t���O
	bool m_is_ground;
	bool m_haskey;
	float m_move_speed = 5;

	//���
	enum {
		eState_Idle,
		eState_Jump,
	};

	//��ԕϐ�
	int m_state;
	//�e��Ԃł̋���
	void StateIdle();
	void StateJump();
public:
	Player(const CVector2D& pos,bool flip);
	void Update();
	void Draw();
	void Collision(Base* b);

	static TexAnimData _anim_data[];
};
