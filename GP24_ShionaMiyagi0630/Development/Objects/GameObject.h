#pragma once

#include"../Utility/Vector2D.h"

enum {
	PLAYER,
	ENEMY,
	BOMB,

	HARPY,
	GOLDENEMY,
	WINGENEMY,
	EnemyBomb,
};

//�Q�[���I�u�W�F�N�g���N���X
class GameObject
{


protected:
	Vector2D location;      //�ʒu���

	Vector2D box_size;   //��`�̑傫��

	double scale;           //�傫��
	double radian;          //����
	double Bombradian;   //�{���̌���
	int image;              //�`�悷��摜
	int sound;              //�Đ����鉹��

	int flip_flag;   //�摜���]�t���O

	int type;   //�I�u�W�F�N�g�̃^�C�v

public:   //����
	GameObject();
	virtual ~GameObject();

	virtual void Initialize();      //����������
	virtual void Update();          //�X�V����
	virtual void Draw() const;      //�`�揈��
	virtual void Finalize();        //�I������

	//�����蔻��ʒm����
	virtual void OnHitCollision(GameObject* hit_object);

	//�ʒu���擾����
	Vector2D GetLocation() const;
	//�ʒu���ύX����
	void SetLocation(const Vector2D& location);

	//�����蔻��̑傫�����擾����
	Vector2D GetBoxSize() const;

	bool flag;   //�t���O�p

	int GetType();   //���g�̃^�C�v�̎擾

	void SetRadian(double radian);   //���a�̎擾
};

