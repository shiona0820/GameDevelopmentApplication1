#pragma once

#include "EnemyBase.h"

class Blinky : public EnemyBase
{
private:
	std::vector<int> bmove_animation;   //�ړ��̃A�j���[�V�����摜

public:
	Blinky();   //�R���X�g���N�^
	~Blinky();  //�f�X�g���N�^

	virtual void Initialize() override;                                //����������
	virtual void Update(float delta_second) override;                  //�X�V����
	virtual void Draw(const Vector2D& screen_offset) const override;   //�`�揈��
	virtual void Finalize() override; //�I������
};

