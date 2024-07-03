#include "GameObject.h"
#include "Bomb.h"

#define D_PIVOT_CENTER
#include"DxLib.h"




//�R���X�g���N�^
GameObject::GameObject() : flag(true), flip_flag(FALSE),
	scale(0.0),
	radian(0.0),
	image(0),
	sound(0),
	box_size(0.0f)
	
{
}

//�f�X�g���N�^
GameObject::~GameObject()
{

}

//����������
void GameObject::Initialize()
{

	

}

//�X�V����
void GameObject::Update()
{

}

//�`�揈��
void GameObject::Draw() const
{
	// �����蔻��̉���
#ifdef D_PIVOT_CENTER
		Vector2D tl = location - (box_size / 2.0f);
	Vector2D br = location + (box_size / 2.0f);

	DrawBoxAA(tl.x, tl.y, br.x, br.y, GetColor(255, 0, 0), FALSE);
#else
		Vector2D tl = location;
	Vector2D br = location + box_size;

	DrawBoxAA(tl.x, tl.y, br.x, br.y, GetColor(255, 0, 0), FALSE);
#endif //D_PIVOT_CENTER

	//�������Ƃɔ��e�摜��`�悷��
	DrawRotaGraphF(location.x, location.y, 1.0, radian, image, TRUE, flip_flag);

	
}

//�I��������
void GameObject::Finalize()
{

}

//�����蔻��ʒm����
void GameObject::OnHitCollision(GameObject* hit_object)
{
	//�����������ɍs������
	flag = FALSE;
}

//�ʒu���擾����
Vector2D GameObject::GetLocation() const
{
	return this->location;
}

//�ʒu���ݒ菈��
void GameObject::SetLocation(const Vector2D& location)
{
	this->location = location;
}

//BoxSize�̑傫���̎擾
Vector2D GameObject::GetBoxSize() const
{
	return box_size;
}

//���g�̃^�C�v�̎擾����
int GameObject::GetType()
{
	//�����̃^�C�v���Q�Ƃ��܂�
	return this->type;
}

//�摜���΂߂ɂ���悤
void GameObject::SetRadian(double radian)
{
	this->Bombradian = radian;
}

