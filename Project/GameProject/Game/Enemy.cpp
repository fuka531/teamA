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
    //画像複製
    m_img = COPY_RESOURCE("Enemy", CImage);
    //再生アニメーション設定
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
            //移動量を設定
            m_pos.x += -move_speed;
            //反転フラグ
            m_flip = true;
            move_flag = true;
        }
        //右移動
        if (player->m_pos.x > m_pos.x + 64) {
            //移動量を設定
            m_pos.x += move_speed;
            //反転フラグ
            m_flip = false;
            move_flag = true;
        }
    }
    */
}


void Enemy::Update() {
    m_pos_old = m_pos;
    //落ちていたら落下状態へ移行
    if (m_is_ground && m_vec.y > GRAVITY * 4)
        m_is_ground = false;
    //重力による落下
    m_vec.y += GRAVITY;
    m_pos += m_vec;
    //アニメーション更新
    m_img.UpdateAnimation();

    if (m_pos.x < -200) {
        SetKill();
    }
}

void Enemy::Draw() {
    //位置設定
    m_img.SetPos(GetScreenPos(m_pos));
    //反転設定
    m_img.SetFlipH(m_flip);
    //描画
    m_img.Draw();
    //当たり判定矩形の表示
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