#include"Enemy.h"
#include"DxLib.h"

//�R���X�g���N�^
Enemy::Enemy() :animation_count(0)
{
	animation[0] = NULL;
	animation[1] = NULL;
}

//�f�X�g���N�^
Enemy::~Enemy()
{

}

//����������
void Enemy::Initialize()
{

	

	//�摜�̓ǂݍ���
	animation[0] = LoadGraph("Resource/images/BoxEnemy/1.png");
	animation[1] = LoadGraph("Resource/images/BoxEnemy/2.png");

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

	
	flip_flag=FALSE;
}

//�X�V����
void Enemy::Update()
{
	

	//�ړ�����
	Movement();
	//�A�j���[�V��������
	AnimeControl(); 

	
}

//�`�揈��
void Enemy::Draw() const
{
	//�e�N���X�̕`�揈�����Ăяo��
	__super::Draw();

	

}

//�I��������
void Enemy::Finalize()
{
	//�g�p�����摜���J������
	DeleteGraph(animation[0]);
	DeleteGraph(animation[1]);
}


//�����蔻��ʒm����
void Enemy::OnHitCollision(GameObject* hit_object)
{
	//�����������̏���
	
	flag = false;
	Finalize();

}



//�ړ�����
void Enemy::Movement()
{
	//direction.x > 640.0f || direction.x < 0.0f
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
		location += direction;
	}

	



//�A�j���[�V��������
void Enemy::AnimeControl()
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


