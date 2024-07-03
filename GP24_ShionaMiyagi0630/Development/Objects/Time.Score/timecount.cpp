#include "timecount.h"

#include"DxLib.h"

#include<time.h>

//コンストラクタ
Timecount::Timecount()
{

	animation[0] = NULL;
	animation[1] = NULL;
	animation[2] = NULL;
	animation[3] = NULL;
	animation[4] = NULL;
	animation[5] = NULL;
	animation[6] = NULL;
	animation[7] = NULL;
	animation[8] = NULL;
	animation[9] = NULL;

}

//デストラクタ
Timecount::~Timecount()
{
	//忘れ防止
	Finalize();
}

//初期化処理
void Timecount::Initialize()
{
	srand(time(NULL));

	//画像の読み込み
	animation[0] = LoadGraph("Resource/images/Score/0.png");
	animation[1] = LoadGraph("Resource/images/Score/1.png");
	animation[2] = LoadGraph("Resource/images/Score/2.png");
	animation[3] = LoadGraph("Resource/images/Score/3.png");
	animation[4] = LoadGraph("Resource/images/Score/4.png");
	animation[5] = LoadGraph("Resource/images/Score/5.png");
	animation[6] = LoadGraph("Resource/images/Score/6.png");
	animation[7] = LoadGraph("Resource/images/Score/7.png");
	animation[8] = LoadGraph("Resource/images/Score/8.png");
	animation[9] = LoadGraph("Resource/images/Score/9.png");

	//エラーチェック
	if (animation[0] == -1)
	{
		throw("数の画像がありません\n");
	}

}

//更新処理
void Timecount::Update()
{
	
	if (Tcount >= 0)
	{
		Tcount--;

		Sec = Tcount / 1950;

		if (Mincount != 0)
		{
			Mincount--;
			Min = Mincount / 195;
		}
		else
		{
			Mincount = 1950;
		}

	}

	
	
}

//描画処理
void Timecount::Draw()
{
	DrawRotaGraphF(85,457,1.0,0,animation[Sec],TRUE);   //十の位の描画
	DrawRotaGraphF(105,457,1.0,0,animation[Min],TRUE);  //一の位の描画

	//DrawFormatString(0, 0, 0xffffff, "変数 i の値は %d です",Tcount);

}

//終了処理
void Timecount::Finalize()
{
	//使用した画像を開放する
	DeleteGraph(animation[0]);
	DeleteGraph(animation[1]);
	DeleteGraph(animation[2]);
	DeleteGraph(animation[3]);
	DeleteGraph(animation[4]);
	DeleteGraph(animation[5]);
	DeleteGraph(animation[6]);
	DeleteGraph(animation[7]);
	DeleteGraph(animation[8]);
	DeleteGraph(animation[9]);
}

//時間制限処理
int Timecount::GetTcount()
{
	return this->Tcount;
}
