#include "Enemy.h"
#include "Field.h"


Enemy::Enemy(const CVector2D& p, bool flip) :
    Base(eType_Enemy) {
    //画像複製
    m_img = COPY_RESOURCE("Enemy", CImage);
    //再生アニメーション設定
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
    //移動中なら
    if (move_flag) {
        //走るアニメーション
        m_img.ChangeAnimation(eAnimRun);
    }
    else {
        //待機アニメーション
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
        //通常状態
    case eState_Idle:
        StateIdle();
        break;
        //ダメージ状態
    case eState_Damage:
        StateDamage();
        break;
        //ダウン状態
    case eState_Down:
        StateDown();
        break;
    }
    //落ちていたら落下状態へ以降
    if (m_is_ground && m_vec.y > GRAVITY * 4)
        m_is_ground = false;
    //重力による落下
    m_vec.y += GRAVITY;
    m_pos += m_vec;
    //アニメーション更新
    m_img.UpdateAnimation();

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
                //落下速度リセット
                m_vec.y = 0;
                //接地フラグON
                m_is_ground = true;
            }
        }
        break;
    case eType_Player:
        break;
    }
    */
}  