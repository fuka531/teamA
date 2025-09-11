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
	//画像複製
	m_img = COPY_RESOURCE("Player", CImage);

	//再生アニメーション設定
	m_img.ChangeAnimation(0);
	//座標設定
	m_pos = pos;
	//画像サイズ
	m_img.SetSize(400,400);
	//中心位置設定
	m_img.SetCenter(200,400);
	//着地フラグ
	m_is_ground = true;

	m_flip = flip;
	//当たり判定用矩形設定
	m_rect = CRect(-32, -64, 32, 0);

}
void Player::StateIdle()
{
	//移動量
	const float move_speed = 5;
	//移動フラグ
	bool move_flag = false;
	//ジャンプ力
	const float jump_pow = 18;
	m_pos.x += move_speed;

	//ジャンプ
	if (m_is_ground && PUSH(CInput::eButton2)) {
		//m_img.ChangeAnimation(7);
		m_vec.y = -jump_pow;
		m_is_ground = false;
	}

}
void Player::Draw()
{
	//位置設定
	m_img.SetPos(GetScreenPos(m_pos));
	//描画
	m_img.Draw();
	//当たり判定の矩形の表示
	DrawRect();
}
void Player::Update()
{
	switch (m_state) {
	case eState_Idle:
		StateIdle();
		break;
	}

	//落ちていたら落下中状態へ移行
	if (m_is_ground && m_vec.y > GRAVITY * 4)
		m_is_ground = false;

	//重力による落下
	m_vec.y += GRAVITY;
	m_pos += m_vec;

	//スクロール設定
	m_scroll.x = m_pos.x - 1280 / 2 ;
	//アニメーション更新
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

