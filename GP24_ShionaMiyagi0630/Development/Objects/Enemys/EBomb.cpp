#include"EBomb.h"
#include"DxLib.h"

#include"../../Utility/InputControl.h"
#include"../GameObject.h"

//�R���X�g���N�^
EBomb::EBomb() :animation_count(0), direction(0.0f)
{
	animation[0] = NULL;
	animation[1] = NULL;
	animation[2] = NULL;
	animation[3] = NULL;

}

//�f�X�g���N�^
EBomb::~EBomb()
{

}

//����������
void EBomb::Initialize()
{
	//�摜�̓ǂݍ���
	//animation[0] = LoadGraph("Resource/images/EnemyBullet/1.png");
	//animation[1] = LoadGraph("Resource/images/EnemyBullet/eff1.png");
	//animation[2] = LoadGraph("Resource/images/EnemyBullet/eff12.png");
	//animation[3] = LoadGraph("Resource/images/EnemyBullet/eff13.png");

	////�G���[�`�F�b�N
	//if (animation[0] == -1 || animation[1] == -1 || animation[2] == -1 || animation[3] == -1)
	//{
	//	throw("�G�{���̉摜������܂���\n");
	//}

	//�����̐ݒ�
	radian = DX_PI_F / 2;

	//�����蔻��̑傫���ݒ�
	box_size = 64.0f;

	//�����������̐ݒ�
	image = animation[0];

	//�����i�s�����̐ݒ�
	direction = Vector2D(0.0f, -1.0f);
	
}

//�X�V����
void EBomb::Update()
{
	//�ړ�����
	Movement();
	//�A�j���[�V��������
	AnimationControl();


}

//�`�揈��
void EBomb::Draw() const
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
void EBomb::Finalize()
{
	//�g�p�����摜���J������
	DeleteGraph(animation[0]);
	DeleteGraph(animation[1]);
	DeleteGraph(animation[2]);
	DeleteGraph(animation[3]);
}

//�����蔻��ʒm����
void EBomb::OnHitCollision(GameObject* hit_object)
{
	//�����������̏���
	//�G�ɂ���������A�G�̓����蔻�������
	flag = false;
	Finalize();
	//direction = 0.0f;

	////�g�p�����摜���J������
	//DeleteGraph(animation[0]);
	//DeleteGraph(animation[1]);
	//DeleteGraph(animation[2]);
	//DeleteGraph(animation[3]);
}

//�ړ�����
void EBomb::Movement()
{
	//�i�s�����Ɍ������āA�ʒu���W��ύX����
	location += direction;
}

//�A�j���[�V��������
void EBomb::AnimationControl()
{
	//�t���[���J�E���g�����Z����
	animation_count++;

}

//�e�̐i�s���� atan=�^���W�F���g�̋t�O�p�`
void EBomb::SetDirection(float x)
{
	direction.x = x;
	Vector2D temp = location - (location - direction);
	radian = atan2f(temp.y, temp.x);
}
