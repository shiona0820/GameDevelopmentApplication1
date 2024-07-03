#include "Fps.h"

#include "DxLib.h"

//‰Šú‰»ˆ—
void Fps::Initialize(float RefreshRate, int UpdateTime)
{
	fream_time = (int)(1000.0f / RefreshRate);   //ƒtƒŒ[ƒ€‚ÌŠÔ‚ÌŒvZ
}
