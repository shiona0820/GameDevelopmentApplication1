#include "timecount.h"

#include"DxLib.h"

#include<time.h>

//�R���X�g���N�^
Timecount::Timecount()
{

	animation[0] = NULL;
	animation[1] = NULL;
	animation[2] = NULL;
	animation[3] = NULL;
	animation[4] = NULL;
	animation[5] = NULL;
	animation[6] = NULL;
	animation[7] = NULL;
	animation[8] = NULL;
	animation[9] = NULL;

}

//�f�X�g���N�^
Timecount::~Timecount()
{
	//�Y��h�~
	Finalize();
}

//����������
void Timecount::Initialize()
{
	srand(time(NULL));

	//�摜�̓ǂݍ���
	animation[0] = LoadGraph("Resource/images/Score/0.png");
	animation[1] = LoadGraph("Resource/images/Score/1.png");
	animation[2] = LoadGraph("Resource/images/Score/2.png");
	animation[3] = LoadGraph("Resource/images/Score/3.png");
	animation[4] = LoadGraph("Resource/images/Score/4.png");
	animation[5] = LoadGraph("Resource/images/Score/5.png");
	animation[6] = LoadGraph("Resource/images/Score/6.png");
	animation[7] = LoadGraph("Resource/images/Score/7.png");
	animation[8] = LoadGraph("Resource/images/Score/8.png");
	animation[9] = LoadGraph("Resource/images/Score/9.png");

	//�G���[�`�F�b�N
	if (animation[0] == -1)
	{
		throw("���̉摜������܂���\n");
	}

}

//�X�V����
void Timecount::Update()
{
	
	if (Tcount >= 0)
	{
		Tcount--;

		Sec = Tcount / 1950;

		if (Mincount != 0)
		{
			Mincount--;
			Min = Mincount / 195;
		}
		else
		{
			Mincount = 1950;
		}

	}

	
	
}

//�`�揈��
void Timecount::Draw()
{
	DrawRotaGraphF(85,457,1.0,0,animation[Sec],TRUE);   //�\�̈ʂ̕`��
	DrawRotaGraphF(105,457,1.0,0,animation[Min],TRUE);  //��̈ʂ̕`��

	//DrawFormatString(0, 0, 0xffffff, "�ϐ� i �̒l�� %d �ł�",Tcount);

}

//�I������
void Timecount::Finalize()
{
	//�g�p�����摜���J������
	DeleteGraph(animation[0]);
	DeleteGraph(animation[1]);
	DeleteGraph(animation[2]);
	DeleteGraph(animation[3]);
	DeleteGraph(animation[4]);
	DeleteGraph(animation[5]);
	DeleteGraph(animation[6]);
	DeleteGraph(animation[7]);
	DeleteGraph(animation[8]);
	DeleteGraph(animation[9]);
}

//���Ԑ�������
int Timecount::GetTcount()
{
	return this->Tcount;
}
