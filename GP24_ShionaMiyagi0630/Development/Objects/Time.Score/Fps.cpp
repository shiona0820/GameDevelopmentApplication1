#include "Fps.h"

#include "DxLib.h"

//初期化処理
void Fps::Initialize(float RefreshRate, int UpdateTime)
{
	fream_time = (int)(1000.0f / RefreshRate);   //フレームの時間の計算
}
