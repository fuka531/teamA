#include "Enemy.h"
#include "Field.h"
#include "Player.h"

static TexAnim _run[] = {
    { 0,4 },
    { 1,5 },
    { 2,4 },
    { 3,5 },
    { 4,4 },
    { 5,5 },

};

TexAnimData Enemy::_anim_data[] = {
    ANIMDATA(_run),
};

Enemy::Enemy(const CVector2D& p, bool flip) :
    Base(eType_Enemy) {
    //�摜����
    m_img = COPY_RESOURCE("Enemy", CImage);
    //�Đ��A�j���[�V�����ݒ�
    m_img.ChangeAnimation(0);
    m_pos_old = m_pos = p;
    m_flip = flip;
    m_is_ground = true;
    m_rect = CRect(-100, -200, 100, 0);
    m_img.SetCenter(100, 200);
    m_img.SetSize(200, 200);
}


void Enemy::StateIdle()
{
    const float move_speed = 8;

    m_pos.x += -move_speed;
    /*bool move_flag = false;
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
    */
}


void Enemy::Update() {
    m_pos_old = m_pos;
    //�����Ă����痎����Ԃֈڍs
    if (m_is_ground && m_vec.y > GRAVITY * 4)
        m_is_ground = false;
    //�d�͂ɂ�闎��
    m_vec.y += GRAVITY;
    m_pos += m_vec;
    //�A�j���[�V�����X�V
    m_img.UpdateAnimation();

    if (m_pos.x < -200) {
        SetKill();
    }
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


    switch (b->m_type) {
    case eType_Field:
        if (Field* f = dynamic_cast<Field*>(b)) {
            if (m_pos.y > f->GetGroundY()) {
                m_pos.y = f->GetGroundY();
                m_vec.y = 0;
                m_is_ground = true;

            }
            break;
        }
    case eType_Player:
        if (Base::CollisionCircle(this, b)) {
            SetKill();
        }
        break;
        }
    }