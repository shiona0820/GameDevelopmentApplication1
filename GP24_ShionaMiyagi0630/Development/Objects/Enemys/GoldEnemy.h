#pragma once

#include "../GameObject.h"

class GoldEnemy : public GameObject
{
private:
	int animation[2];    //�A�j���[�V�����摜
	int animation_count; //�A�j���[�V��������

	Vector2D direction;   //�i�s����

public:
	GoldEnemy();
	~GoldEnemy();

	virtual void Initialize() override;      //����������
	virtual void Update() override;          //�X�V����
	virtual void Draw() const override;      //�`�揈��
	virtual void Finalize() override;        //�I������

	//�����蔻��ʒm����
	virtual void OnHitCollision(GameObject* hit_object) override;

private:
	//�ړ�����
	void Movement();
	//�A�j���[�V��������
	void AnimeControl();
};

