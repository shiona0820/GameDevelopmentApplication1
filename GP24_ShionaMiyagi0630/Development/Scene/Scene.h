#pragma once
#define D_PIVOT_CENTER

#include<vector>
#include"../Objects/GameObject.h"
#include"../Objects/Time.Score/timecount.h"
#include"../Objects/Enemys/EBomb.h"
#include"../Objects/Enemys/Enemy.h"


class Scene
{
private:
	std::vector<GameObject*>objects;

	Timecount*timecount;   //scene��timecount���Ăяo����悤��

	int imageback;   //�w�i�̕`��
	int clockimage;   //���v�̕`��
	int Finishimage;   //�I���̕`��

	int Enemycount;   //�G�̐�����
	int count;   //���Ԍo��

	int MainSE;   //�Q�[�����C��SE
	int FinishSE;   //���ԏI��SE

	Vector2D EnemyBomb;   //�G�̔��e���v���C���[�Ɍ������Ĕ��ł���
	Vector2D EBdirection;   //�G�U���̈ʒu���W

	//EBomb* ebomb;

public:
	Scene();
	~Scene();

	//����������
	void Initialize();
	//�X�V����
	void Update();
	//�`�揈��
	void Draw() const;
	//�I������
	void Finalize();

	

private:
	//�����蔻��`�F�b�N����
	void HitCheckObject(GameObject* a, GameObject* b);

	//�I�u�W�F�N�g��������
	template <class T>
	T* CreateObject(const Vector2D& location)
	{
		//�w�肵���N���X�𐶐�����
		T* new_instance = new T();
		//GameObject�N���X���p�����Ă��邩�m�F
		GameObject* new_object = dynamic_cast<GameObject*>(new_instance);

		//�G���[�`�F�b�N
		if (new_object == nullptr)
		{
			delete new_instance;
			throw ("�Q�[���I�u�W�F�N�g�������ł��܂���ł���");
		}

		//����������
		new_object->Initialize();
		//�ʒu���̐ݒ�
		new_object->SetLocation(location);

		//�I�u�W�F�N�g���X�g�ɒǉ�
		objects.push_back(new_object);

		//�C���X�^���X�̃|�C���^��ԋp
		return new_instance;
	}

};

