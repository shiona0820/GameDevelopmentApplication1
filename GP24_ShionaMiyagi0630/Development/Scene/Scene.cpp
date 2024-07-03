#include "Scene.h"

#include<time.h>

#include"../Objects/Enemys/Enemy.h"
#include"../Objects/Player/Player.h"
#include"../Objects/Enemys/Harpy.h"
#include"../Objects/Enemys/WingEnemy.h"
#include"../Objects/Enemys/GoldEnemy.h"
#include"../Objects/Bomb.h"
#include"../Objects/Enemys/EBomb.h"
#include "../Objects/Time.Score/Fps.h"
#include"../Utility/InputControl.h"
#include"../Objects/GameObject.h"
#include"DxLib.h"

//�R���X�g���N�^
Scene::Scene() : objects()
{
	imageback = NULL;
	clockimage = NULL;
	Finishimage = NULL;

	Enemycount = NULL;
	count = NULL;
	timecount = NULL;

	bool Leftdiagonal = NULL;
	bool Rightdiagonal = NULL;

	MainSE = NULL;
	FinishSE = NULL;

}

//�f�X�g���N�^
Scene::~Scene()
{
	//�Y��h�~
	Finalize();
}

//����������
void Scene::Initialize()
{

	timecount = new Timecount;   //timecount->Draw()���g����悤��

	timecount->Initialize();

	srand(time(NULL));

	//�G�����ő吔10
	Enemycount = 10;

	count = 0;

	//�v���C���[�𐶐�����
	CreateObject<Player>(Vector2D(320.0f, 94.0f));

	clockimage = LoadGraph("Resource/images/timeLimit/timer-03.png");   //���v�̉摜�̓ǂݍ���
	imageback = LoadGraph("Resource/images/BackGround.png");            //�w�i�摜�̓ǂݍ���
	Finishimage = LoadGraph("Resource/images/Evaluation/Finish.png");   //�I���̕����̕\��

	MainSE = LoadSoundMem("Resource/Sounds/Evaluation/BGM_arrows.wav"); //���C��BGM�̓ǂݍ���
	FinishSE = LoadSoundMem("Resource/Sounds/Evaluation/BGM_timeup.wav");//�I������BGM�̓ǂݍ���

}

//�X�V����
void Scene::Update()
{

	//�������Ԃ�0���傫��������
	if (timecount->GetTcount() >= 0)
	{
		//SE������Ă��Ȃ��Ƃ��ɍĐ�
		if (CheckSoundMem(MainSE) != TRUE)
		{
			//���C��SE�̍Đ�
			PlaySoundMem(MainSE, DX_PLAYTYPE_LOOP, TRUE);
		}

		timecount->Update();

		//�J�E���g+�P����
		count++;

		//�����AEnemycount��0�ȏ�Ȃ�
		//Enemy��\������
		if (Enemycount > 0 && count > 300)
		{
			int s;
			count = 0;
			s = rand() % 4;

			switch (s)
			{
			case 0:
				CreateObject<Enemy>(Vector2D(100.0f, 420.0f));   //�G�̕`��
				

				break;

			case 1:
				CreateObject<GoldEnemy>(Vector2D(200.0f, 420.0f));   //�G�̕`��

				break;

			case 2:
				CreateObject<Harpy>(Vector2D(200.0f, 220.0f));   //�G�̕`��

				break;

			case 3:
				CreateObject<WingEnemy>(Vector2D(100.0f, 320.0f));   //�G�̕`��

				break;

			default:
				break;
			}

			//�G������ -1
			Enemycount--;
		}

		//�V�[���ɑ��݂���I�u�W�F�N�g�̍X�V����
		for (GameObject* obj : objects)
		{

			if (obj->flag == true)
			{
				obj->Update();
				obj->SetRadian(2.0f);
			}

		}

		for (int i = 1; i < objects.size(); i++)
		{
			if (objects[i]->flag == true)
			{
				for (int j = i + 1; j < objects.size(); j++)
				{
					if (objects[j]->flag == true)
					{
						//�����蔻��`�F�b�N����
						HitCheckObject(objects[i], objects[j]);
					}

				}
			}

		}

		//�ړ����Ȃ���ł��Ă��邩
		if (InputControl::GetKey(KEY_INPUT_LEFT))   //�\���L�[�̍���������Ă�����
		{
			if (InputControl::GetKeyDown(KEY_INPUT_SPACE))   //���e�𗎂Ƃ��{�^����������Ă�����
			{
				Bomb* bomb = CreateObject<Bomb>(objects[0]->GetLocation());
				bomb->SetDirection(-1.0f);
			}
		}
		else if (InputControl::GetKey(KEY_INPUT_RIGHT))   //�\���L�[�̉E�������ꂦ�Ă�����
		{
			if (InputControl::GetKeyDown(KEY_INPUT_SPACE))   //���e�𗎂Ƃ��{�^����������Ă�����
			{

				Bomb* bomb = CreateObject<Bomb>(objects[0]->GetLocation());
				bomb->SetDirection(1.0f);

			}
		}
		else if (InputControl::GetKeyDown(KEY_INPUT_SPACE))   //���e�𗎂Ƃ��{�^��������������Ă�����
		{
			CreateObject<Bomb>(objects[0]->GetLocation());   //�^���ɔ��e�𗎂Ƃ�
		}
	}
	if (timecount->GetTcount() <= 0)
	{
		StopSoundMem(MainSE);   //���C��SE�̒�~
	}
	
	
}


//�`�揈��
void Scene::Draw() const
{
	DrawExtendGraph(0, 0, 640,480,imageback, FALSE);   //�w�i�̕`��
	DrawExtendGraph(0,440, 40, 480, clockimage,FALSE);   //���v�̕`��
	//�V�[���ɑ��݂���I�u�W�F�N�g�̕`�揈��
	for (GameObject* obj : objects)
	{

		
		if (obj->flag == true)
		{
			obj->Draw();
		}
	}

	timecount->Draw();

	//���C����BGM������Ă��Ȃ�������
	if (CheckSoundMem(MainSE) != TRUE)
	{
		DrawExtendGraph(120, 100, 520, 300, Finishimage, TRUE);   //�I���̕����̕`��
		//PlaySoundMem(FinishSE, DX_PLAYTYPE_NORMAL, TRUE);   //�I��SE�̍Đ�(�Đ�������ESC�L�[�������Ȃ�)
	}
}

//�I������
void Scene::Finalize()
{
	//���I�z�񂪋�Ȃ珈�����I������
	if (objects.empty())
	{
		return;
	}

	//�e�I�u�W�F�N�g���폜����
	for (GameObject* obj : objects)
	{
		obj->Finalize();
		delete obj;
	}

	//���I�z��̉��
	objects.clear();
}

#ifdef D_PIVOT_CENTER


//�����蔻��`�F�b�N�����i��`�̒��S�œ����蔻����Ƃ�j
void Scene::HitCheckObject(GameObject* a, GameObject* b)
{
	//2�̃I�u�W�F�N�g�̋������擾
	Vector2D diff = a->GetLocation() - b->GetLocation();

	//2�̃I�u�W�F�N�g�̓����蔻��̑傫�����擾
	Vector2D box_size = (a->GetBoxSize() + b->GetBoxSize()) / 2.0f;

	//�������傫�����傫���ꍇ�AHit����Ƃ���
	if ((fabs(diff.x) < box_size.x) && (fabsf(diff.y) < box_size.y))
	{
		if (a->GetType() == b->GetType())
		{
			return;
		}
		else
		{
			//�����������Ƃ��I�u�W�F�N�g�ɒʒm����
			a->OnHitCollision(b);
			b->OnHitCollision(a);

			//Enemycount�𑝂₷�i�ő�G�o������10�ɂ��邽�߁j
			Enemycount++;
		}
	}
}

#else

//�����蔻��`�F�b�N�����i���㒸�_�̍��W���瓖���蔻��v�Z���s��)
void Scene::HitCheckObject(GameObject* a, GameObject* b)
{
	//�E�����_���W���擾����
	Vector2D a_lower_right = a->GetLocation() + a->GetBoxSize();
	Vector2D b_lower_right = b->GetLocation() + b->GetBoxSize();

	//��`A�Ƌ�`B�̈ʒu�֌W�𒲂ׂ�
	if ((a->GetLocation().x < b_lower_right.x) &&
		(a->GetLocation().y < b_lower_right.y) &&
		(a_lower_right.x > b->GetLocation().x) &&
		(a_lower_right.y > b->GetLocation().y))
	{
		//�I�u�W�F�N�g�ɂ�������Hit�����ʒm����
		a->OnHitCollision(b);
		b->OnHitCollision(a);
	}
}
#endif // D_PIVOT_CNETER
