#include "Enemy.h"
#include "Field.h"


Enemy::Enemy(const CVector2D& p, bool flip) :
    Base(eType_Enemy) {
    //�摜����
    m_img = COPY_RESOURCE("Enemy", CImage);
    //�Đ��A�j���[�V�����ݒ�
    m_img.ChangeAnimation(0);
    m_pos_old = m_pos = p;
    m_flip = flip;
    m_is_ground = true;
    m_rect = CRect(-32, -64, 32, 0);
    m_img.SetCenter(32, 32);
    m_img.SetSize(64, 64);
}


void Enemy::StateIdle()
{
    const float move_speed = 6;
    bool move_flag = false;
    Base* player = Base::FindObject(eType_Player);
    if (player) {
        if (player->m_pos.x < m_pos.x - 64) {
            //�ړ��ʂ�ݒ�
            m_pos.x += -move_speed;
            //���]�t���O
            m_flip = true;
            move_flag = true;
        }
        //�E�ړ�
        if (player->m_pos.x > m_pos.x + 64) {
            //�ړ��ʂ�ݒ�
            m_pos.x += move_speed;
            //���]�t���O
            m_flip = false;
            move_flag = true;
        }
    }
    //�ړ����Ȃ�
    if (move_flag) {
        //����A�j���[�V����
        m_img.ChangeAnimation(eAnimRun);
    }
    else {
        //�ҋ@�A�j���[�V����
        m_img.ChangeAnimation(eAnimIdle);
    }

}

void Enemy::StateDamage()
{
    m_img.ChangeAnimation(eAnimDamage, false);
    if (m_img.CheckAnimationEnd()) {
        m_state = eState_Idle;
    }
}

void Enemy::StateDown()
{
}

void Enemy::Update() {
    m_pos_old = m_pos;
    switch (m_state) {
        //�ʏ���
    case eState_Idle:
        StateIdle();
        break;
        //�_���[�W���
    case eState_Damage:
        StateDamage();
        break;
        //�_�E�����
    case eState_Down:
        StateDown();
        break;
    }
    //�����Ă����痎����Ԃֈȍ~
    if (m_is_ground && m_vec.y > GRAVITY * 4)
        m_is_ground = false;
    //�d�͂ɂ�闎��
    m_vec.y += GRAVITY;
    m_pos += m_vec;
    //�A�j���[�V�����X�V
    m_img.UpdateAnimation();

}

void Enemy::Draw() {
    //�ʒu�ݒ�
    m_img.SetPos(GetScreenPos(m_pos));
    //���]�ݒ�
    m_img.SetFlipH(m_flip);
    //�`��
    m_img.Draw();
    //�����蔻���`�̕\��
    DrawRect();

}

void Enemy::Collision(Base* b) {
  /*
    switch (b->m_type) {
    case eType_Field:
        if (Field* f = dynamic_cast<Field*>(b)) {
            int t;
            t = f->CollisionRect(b, f);
            if (t != 0) {
                m_pos.x = m_pos_old.x;
            }
            t = f->CollisionRect(b, f);
            if (t != 0) {
                m_pos.y = m_pos_old.y;
                //�������x���Z�b�g
                m_vec.y = 0;
                //�ڒn�t���OON
                m_is_ground = true;
            }
        }
        break;
    case eType_Player:
        break;
    }
    */
}  