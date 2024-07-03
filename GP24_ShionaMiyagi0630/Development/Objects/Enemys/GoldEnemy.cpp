#include"GoldEnemy.h"
#include"DxLib.h"

//�R���X�g���N�^
GoldEnemy::GoldEnemy() :animation_count(0)
{
	animation[0] = NULL;
	animation[1] = NULL;
}

//�f�X�g���N�^
GoldEnemy::~GoldEnemy()
{

}

//����������
void GoldEnemy::Initialize()
{
	//�摜�̓ǂݍ���
	animation[0] = LoadGraph("Resource/images/GoldEnemy/1.png");
	animation[1] = LoadGraph("Resource/images/GoldEnemy/2.png");

	//�G���[�`�F�b�N
	if (animation[0] == -1 || animation[1] == -1)
	{
		throw("�n�R�e�L�̉摜������܂���\n");
	}

	//�����̐ݒ�
	radian = 0.0;

	//�����蔻��̑傫����ݒ�
	box_size = 64.0f;

	//�����������̐ݒ�
	image = animation[0];

	//�����i�s�����̐ݒ�
	direction = Vector2D(1.0f, 0.0f);

	flip_flag = FALSE;

}

//�X�V����
void GoldEnemy::Update()
{
	//�ړ�����
	Movement();
	//�A�j���[�V��������
	AnimeControl();

}

//�`�揈��
void GoldEnemy::Draw() const
{
	//���]�O���t
	int flip_flag = FALSE;

	//�i�s�����ɂ���āA���]��Ԃ����肷��
	if (direction.x > 0.0f)
	{
		flip_flag = FALSE;
	}
	else
	{
		flip_flag = TRUE;
	}

	//������Ƀn�R�e�L�摜��`�悷��
	DrawRotaGraphF(location.x, location.y, 1.0, radian, image, TRUE, flip_flag);

	//�e�N���X�̕`�揈�����Ăяo��
	__super::Draw();

}

//�I��������
void GoldEnemy::Finalize()
{
	//�g�p�����摜���J������
	DeleteGraph(animation[0]);
	DeleteGraph(animation[1]);
}


//�����蔻��ʒm����
void GoldEnemy::OnHitCollision(GameObject* hit_object)
{
	//�����������̏���
	flag = false;
	Finalize();
}



//�ړ�����
void GoldEnemy::Movement()
{
	//��ʒ[�ɓ��B������A�i�s�����𔽓]����
	if (((location.x + direction.x) < box_size.x) ||
		(640.0f - box_size.x) < (location.x + direction.x))
	{
		//�[�ɓ��B������ړ����������˕Ԃ�
		direction.x = -direction.x;


		//�`�捶�E���ւ���
		if (direction.x > 0.0f)
		{
			flip_flag = FALSE;
		}
		else
		{
			flip_flag = TRUE;
		}
	}


	//direction.x *= -1.0f;
	//�i�s�����Ɍ������āA�ʒu����ύX����
	location += direction;
}


//�A�j���[�V��������
void GoldEnemy::AnimeControl()
{
	//�t���[���J�E���g�����Z����
	animation_count++;

	//60�t���[���ڂɒB��������
	if (animation_count >= 60)
	{
		//�J�E���g�̃��Z�b�g
		animation_count = 0;
		{
			//�摜�̐؂�ւ�
			if (image == animation[0])
			{
				image = animation[1];
			}
			else
			{
				image = animation[0];
			}
		}
	}

}


