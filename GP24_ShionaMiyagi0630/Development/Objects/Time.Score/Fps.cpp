#include "Fps.h"

#include "DxLib.h"

//����������
void Fps::Initialize(float RefreshRate, int UpdateTime)
{
	fream_time = (int)(1000.0f / RefreshRate);   //�t���[���̎��Ԃ̌v�Z
}
