#include "object.h"
#include "Field.h"

Object::Object(const CVector2D& pos, bool flip) :Base(eType_Object) {
	//画像複製
	m_img = COPY_RESOURCE("Object", CImage);
	//座標設定
	m_pos = pos;
	m_img.SetSize(200,200);
	//中心位置設定
	m_img.SetCenter(20, 40);

	m_flip = flip;
	//当たり判定矩形設定
	m_rect = CRect(0, -30,150, 150);
}

void Object::Draw()
{
	//位置設定
	m_img.SetPos(GetScreenPos(m_pos));
	//反転設定
	m_img.SetFlipH(m_flip);
	//描画
	m_img.Draw();
	//当たり判定矩形の表示
	DrawRect();
}
void Object::Update()
{

}
void Object::Collision(Base* b)
{
}