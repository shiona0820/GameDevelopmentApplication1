#pragma once
class Fps
{
private:

	int fream_time;   //�t���[���̎��Ԑݒ�

private:

	void Initialize(float RefreshRate, int UpdateTime);   //����������

public:

	//�R���X�g���N�^
	Fps(float RefreshRate, int UpdateTime)
	{
		Initialize(RefreshRate, UpdateTime);
	}

	Fps()
	{
		Initialize(60.0f, 800);
	}

};

