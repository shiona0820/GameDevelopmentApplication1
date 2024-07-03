#pragma once
class Fps
{
private:

	int fream_time;   //フレームの時間設定

private:

	void Initialize(float RefreshRate, int UpdateTime);   //初期化処理

public:

	//コンストラクタ
	Fps(float RefreshRate, int UpdateTime)
	{
		Initialize(RefreshRate, UpdateTime);
	}

	Fps()
	{
		Initialize(60.0f, 800);
	}

};

