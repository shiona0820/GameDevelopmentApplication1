#pragma once
//#define TIME_LIMIT (9000)

class Timecount
{
private:

	

	int Tcount = 11700;   //���ԃJ�E���g
	int Mincount = 1950;   //10�b�J�E���g�p

	int animation[10] = {};   //�z������������Ă���
	int Min = 6;   //��
	int Sec = 9;   //�b

	

public:
	Timecount();
	~Timecount();

	//����������
	void Initialize();
	//�X�V����
	void Update();
	//�`�揈��
	void Draw();
	//�I������
	void Finalize();

	//���g�̃^�C�v�̎擾
	int GetTcount();
	
};

