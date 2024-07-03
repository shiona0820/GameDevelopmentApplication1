#include"Bomb.h"
#include"DxLib.h"

#include"../Utility/InputControl.h"

//�R���X�g���N�^
Bomb::Bomb() :animation_count(0), direction(0.0f)
{
	animation[0] = NULL;
	animation[1] = NULL;
	animation[2] = NULL;
	animation[3] = NULL;

}

//�f�X�g���N�^
Bomb::~Bomb()
{

}

//����������
void Bomb::Initialize()
{
	//�摜�̓ǂݍ���
	animation[0] = LoadGraph("Resource/images/Bomb/Bomb.png");
	animation[1] = LoadGraph("Resource/images/Blast/1.png");
	animation[2] = LoadGraph("Resource/images/Blast/2.png");
	animation[3] = LoadGraph("Resource/images/Blast/3.png");

	//�G���[�`�F�b�N
	if (animation[0] == -1 || animation[1] == -1 || animation[2] == -1 || animation[3] == -1)
	{
		throw("�{���̉摜������܂���\n");
	}

	//�����̐ݒ�
	radian = DX_PI_F / 2;

	//�����蔻��̑傫���ݒ�
	box_size = 64.0f;

	//�����������̐ݒ�
	image = animation[0];

	//�����i�s�����̐ݒ�
	direction = Vector2D(0.0f, 1.0f);
	directionA = Vector2D(1.0f, 1.0f);

	//���g�̃^�C�v�̎擾
	type = BOMB;
}

//�X�V����
void Bomb::Update()
{
	//�ړ�����
	Movement();
	//�A�j���[�V��������
	AnimeControl();
	
	
}

//�`�揈��
void Bomb::Draw() const
{
	if (flag == true)
	{
		__super::Draw();
	}
}

//�I��������
void Bomb::Finalize()
{
	//�g�p�����摜���J������
	DeleteGraph(animation[0]);
	DeleteGraph(animation[1]);
	DeleteGraph(animation[2]);
	DeleteGraph(animation[3]);
}

//�����蔻��ʒm����
void Bomb::OnHitCollision(GameObject* hit_object)
{
	flag = false;
	Finalize();
}

//�ړ�����
void Bomb::Movement()
{
	//�i�s�����Ɍ������āA�ʒu���W��ύX����
	location += direction;
}

//�A�j���[�V��������
void Bomb::AnimeControl()
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

//�e�̐i�s���� atan=�^���W�F���g�̋t�O�p�`
void Bomb::SetDirection(float x)
{
	direction.x = x;
	Vector2D temp = location - (location - direction);
	radian = atan2f(temp.y, temp.x);
}
