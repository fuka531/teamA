#include "object.h"
#include "Field.h"

Object::Object(const CVector2D& pos, bool flip) :Base(eType_Object) {
	//�摜����
	m_img = COPY_RESOURCE("Object", CImage);
	//���W�ݒ�
	m_pos = pos;
	m_img.SetSize(300,300);
	//���S�ʒu�ݒ�
	m_img.SetCenter(100,100);

	m_flip = flip;
	//�����蔻���`�ݒ�
	m_rect = CRect(20, 0,110, 150);
}

void Object::Draw()
{
	//�ʒu�ݒ�
	m_img.SetPos(GetScreenPos(m_pos));
	//���]�ݒ�
	m_img.SetFlipH(m_flip);
	//�`��
	m_img.Draw();
	//�����蔻���`�̕\��
	//DrawRect();
}
void Object::Update()
{

}
void Object::Collision(Base* b)
{
}