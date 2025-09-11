#include "Player.h"
#include "Field.h"


static TexAnim _idle[] = {
	{ 0,4 },
	//{ 1,5 },
	{ 2,4 },
	//{ 3,5 },
	{ 4,4 },
	//{ 5,5 },

};

static TexAnim  _jumpUP[] = {
	{ 6,10 },


};
static TexAnim _jumpDOWN[] = {
	{ 6,10 },

};

TexAnimData Player::_anim_data[] = {
	ANIMDATA(_idle),
	ANIMDATA(_jumpUP),
	ANIMDATA(_jumpDOWN),
};

Player::Player(const CVector2D& pos, bool flip) :Base(eType_Player)
{
	//�摜����
	m_img = COPY_RESOURCE("Player", CImage);

	//�Đ��A�j���[�V�����ݒ�
	m_img.ChangeAnimation(0);
	//���W�ݒ�
	m_pos = pos;
	//�摜�T�C�Y
	m_img.SetSize(400,400);
	//���S�ʒu�ݒ�
	m_img.SetCenter(200,400);
	//���n�t���O
	m_is_ground = true;

	m_flip = flip;
	//�����蔻��p��`�ݒ�
	m_rect = CRect(-32, -64, 32, 0);

}
void Player::StateIdle()
{
	//�ړ���
	const float move_speed = 5;
	//�ړ��t���O
	bool move_flag = false;
	//�W�����v��
	const float jump_pow = 18;
	m_pos.x += move_speed;

	//�W�����v
	if (m_is_ground && PUSH(CInput::eButton2)) {
		//m_img.ChangeAnimation(7);
		m_vec.y = -jump_pow;
		m_is_ground = false;
	}

}
void Player::Draw()
{
	//�ʒu�ݒ�
	m_img.SetPos(GetScreenPos(m_pos));
	//�`��
	m_img.Draw();
	//�����蔻��̋�`�̕\��
	DrawRect();
}
void Player::Update()
{
	switch (m_state) {
	case eState_Idle:
		StateIdle();
		break;
	}

	//�����Ă����痎������Ԃֈڍs
	if (m_is_ground && m_vec.y > GRAVITY * 4)
		m_is_ground = false;

	//�d�͂ɂ�闎��
	m_vec.y += GRAVITY;
	m_pos += m_vec;

	//�X�N���[���ݒ�
	m_scroll.x = m_pos.x - 1280 / 2 ;
	//�A�j���[�V�����X�V
	m_img.UpdateAnimation();

}
void Player::Collision(Base* b)
{
	switch (b->m_type) {
	case eType_Field:
		if (Field* f = dynamic_cast<Field*>(b)) {
			if (m_pos.y > f->GetGroundY()) {
				m_pos.y = f->GetGroundY();
				m_vec.y = 0;
				m_is_ground = true;

			}
		}
		break;
	case eType_Object:
		if (Base::CollisionRect(this,b)) {
			SetKill();
			b->SetKill();
		}
		break;
	}
}

