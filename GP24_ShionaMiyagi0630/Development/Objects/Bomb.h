#pragma once
#define DEBUG

#include "GameObject.h"
#include <vector>

class Bomb : public GameObject
{
private:
	std::vector<GameObject*>objects;

	int animation[4];    //�A�j���[�V�����摜
	int animation_count; //�A�j���[�V��������

	Vector2D direction;   //�i�s����
	Vector2D directionA;   //�΂ߗp

	


public:
	Bomb();
	~Bomb();

	virtual void Initialize() override;      //����������
	virtual void Update() override;          //�X�V����
	virtual void Draw() const override;      //�`�揈��
	virtual void Finalize() override;        //�I������

	//�����蔻��ʒm����
	virtual void OnHitCollision(GameObject* hit_object) override;
	void SetDirection(float x);
private:
	//�ړ�����
	void Movement();
	//�A�j���[�V��������
	void AnimeControl();

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

