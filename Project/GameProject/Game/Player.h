#pragma once
#include "../Base/Base.h"

class Player : public Base {
private:
	//�A�j���[�V�����̎��
	enum {
		eAnimIdle,
	};

	CImage m_img;
	bool   m_flip;
	//���n�t���O
	bool m_is_ground;

	//���
	enum {
		eState_Idle,
	};

	//��ԕϐ�
	int m_state;
	//�e��Ԃł̋���
	void StateIdle();
public:
	Player(const CVector2D& pos,bool flip);
	void Update();
	void Draw();
	void Collision(Base* b);

	static TexAnimData _anim_data[];
};
