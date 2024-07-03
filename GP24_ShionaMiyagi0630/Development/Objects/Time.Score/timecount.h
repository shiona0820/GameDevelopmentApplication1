#pragma once
//#define TIME_LIMIT (9000)

class Timecount
{
private:

	

	int Tcount = 11700;   //時間カウント
	int Mincount = 1950;   //10秒カウント用

	int animation[10] = {};   //配列を初期化している
	int Min = 6;   //分
	int Sec = 9;   //秒

	

public:
	Timecount();
	~Timecount();

	//初期化処理
	void Initialize();
	//更新処理
	void Update();
	//描画処理
	void Draw();
	//終了処理
	void Finalize();

	//自身のタイプの取得
	int GetTcount();
	
};

