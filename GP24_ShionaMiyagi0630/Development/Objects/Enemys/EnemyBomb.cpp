#include"EnemyBomb.h"
#include"DxLib.h"

//�R���X�g���N�^
EnemyBomb::EnemyBomb() :animation_count(0), direction(0.0f)
{
	animation[0] = NULL;
	animation[1] = NULL;
	animation[2] = NULL;
	animation[3] = NULL;
}

//�f�X�g���N�^
EnemyBomb::~EnemyBomb()
{

}

//����������
void EnemyBomb::Initialize()
{
	//�摜�̓ǂݍ���
	animation[0] = LoadGraph("Resource/images/EnemyBomb/1.png");
	animation[1] = LoadGraph("Resource/images/EnemyBomb/2.png");
	animation[2] = LoadGraph("Resource/images/EnemyBomb/3.png");
	animation[3] = LoadGraph("Resource/images/EnemyBomb/4.png");

	//�G���[�`�F�b�N
	if (animation[0] == -1 || animation[1] == -1 || animation[2] == -1 || animation[3] == -1)
	{
		throw("�G�{���̉摜������܂���\n");
	}

	//�����̐ݒ�
	radian = DX_PI_F / 2;

	//�����蔻��̑傫���ݒ�
	box_size = 64.0f;

	//�����������̐ݒ�
	image = animation[0];

	//�����i�s�����̐ݒ�
	direction = Vector2D(0.0f, 1.0f);

	type = BOMB;
}

//�X�V����
void EnemyBomb::Update()
{
	//�ړ�����
	Movement();
	//�A�j���[�V��������
	AnimeControl();
}

//�`�揈��
void EnemyBomb::Draw() const
{
	if (flag == true)
	{
		__super::Draw();
	}


	//�������Ƃɔ��e�摜��`�悷��
	//DrawRotaGraphF(location.x, location.y, 1.0, radian, image, TRUE);

	//�e�N���X�̕`�揈�����Ăяo��

}

//�I��������
void EnemyBomb::Finalize()
{
	//�g�p�����摜���J������
	DeleteGraph(animation[0]);
	DeleteGraph(animation[1]);
	DeleteGraph(animation[2]);
	DeleteGraph(animation[3]);
}

//�����蔻��ʒm����
void EnemyBomb::OnHitCollision(GameObject* hit_object)
{
	//�����������̏���
	//�G�ɂ���������A�G�̓����蔻�������
	flag = false;
	Finalize();

}

//�ړ�����
void EnemyBomb::Movement()
{
	//�i�s�����Ɍ������āA�ʒu���W��ύX����
	location += direction;
}

//�A�j���[�V��������
void EnemyBomb::AnimeControl()
{
	//�t���[���J�E���g�����Z����
	animation_count++;

	//60�t���[���ڂɓ��B������,�܂��͓G�ɓ���������
	if (animation_count >= 300)
	{
		//�摜�̐؂�ւ�
		if (image == animation[0])
		{
			radian = 0.0;
			direction = 0.0f;
			image = animation[1];
		}
		
	}
}