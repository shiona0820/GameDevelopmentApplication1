#include "Scene.h"

#include<time.h>

#include"../Objects/Enemys/Enemy.h"
#include"../Objects/Player/Player.h"
#include"../Objects/Enemys/Harpy.h"
#include"../Objects/Enemys/WingEnemy.h"
#include"../Objects/Enemys/GoldEnemy.h"
#include"../Objects/Bomb.h"
#include"../Objects/Enemys/EBomb.h"
#include "../Objects/Time.Score/Fps.h"
#include"../Utility/InputControl.h"
#include"../Objects/GameObject.h"
#include"DxLib.h"

//コンストラクタ
Scene::Scene() : objects()
{
	imageback = NULL;
	clockimage = NULL;
	Finishimage = NULL;

	Enemycount = NULL;
	count = NULL;
	timecount = NULL;

	bool Leftdiagonal = NULL;
	bool Rightdiagonal = NULL;

	MainSE = NULL;
	FinishSE = NULL;

}

//デストラクタ
Scene::~Scene()
{
	//忘れ防止
	Finalize();
}

//初期化処理
void Scene::Initialize()
{

	timecount = new Timecount;   //timecount->Draw()を使えるように

	timecount->Initialize();

	srand(time(NULL));

	//敵生成最大数10
	Enemycount = 10;

	count = 0;

	//プレイヤーを生成する
	CreateObject<Player>(Vector2D(320.0f, 94.0f));

	clockimage = LoadGraph("Resource/images/timeLimit/timer-03.png");   //時計の画像の読み込み
	imageback = LoadGraph("Resource/images/BackGround.png");            //背景画像の読み込み
	Finishimage = LoadGraph("Resource/images/Evaluation/Finish.png");   //終了の文字の表示

	MainSE = LoadSoundMem("Resource/Sounds/Evaluation/BGM_arrows.wav"); //メインBGMの読み込み
	FinishSE = LoadSoundMem("Resource/Sounds/Evaluation/BGM_timeup.wav");//終了時のBGMの読み込み

}

//更新処理
void Scene::Update()
{

	//制限時間が0より大きかったら
	if (timecount->GetTcount() >= 0)
	{
		//SEが流れていないときに再生
		if (CheckSoundMem(MainSE) != TRUE)
		{
			//メインSEの再生
			PlaySoundMem(MainSE, DX_PLAYTYPE_LOOP, TRUE);
		}

		timecount->Update();

		//カウント+１する
		count++;

		//もし、Enemycountが0以上なら
		//Enemyを表示する
		if (Enemycount > 0 && count > 300)
		{
			int s;
			count = 0;
			s = rand() % 4;

			switch (s)
			{
			case 0:
				CreateObject<Enemy>(Vector2D(100.0f, 420.0f));   //敵の描画
				

				break;

			case 1:
				CreateObject<GoldEnemy>(Vector2D(200.0f, 420.0f));   //敵の描画

				break;

			case 2:
				CreateObject<Harpy>(Vector2D(200.0f, 220.0f));   //敵の描画

				break;

			case 3:
				CreateObject<WingEnemy>(Vector2D(100.0f, 320.0f));   //敵の描画

				break;

			default:
				break;
			}

			//敵生成数 -1
			Enemycount--;
		}

		//シーンに存在するオブジェクトの更新処理
		for (GameObject* obj : objects)
		{

			if (obj->flag == true)
			{
				obj->Update();
				obj->SetRadian(2.0f);
			}

		}

		for (int i = 1; i < objects.size(); i++)
		{
			if (objects[i]->flag == true)
			{
				for (int j = i + 1; j < objects.size(); j++)
				{
					if (objects[j]->flag == true)
					{
						//当たり判定チェック処理
						HitCheckObject(objects[i], objects[j]);
					}

				}
			}

		}

		//移動しながら打っているか
		if (InputControl::GetKey(KEY_INPUT_LEFT))   //十字キーの左が押されていたら
		{
			if (InputControl::GetKeyDown(KEY_INPUT_SPACE))   //爆弾を落とすボタンが押されていたら
			{
				Bomb* bomb = CreateObject<Bomb>(objects[0]->GetLocation());
				bomb->SetDirection(-1.0f);
			}
		}
		else if (InputControl::GetKey(KEY_INPUT_RIGHT))   //十字キーの右が押されえていたら
		{
			if (InputControl::GetKeyDown(KEY_INPUT_SPACE))   //爆弾を落とすボタンが押されていたら
			{

				Bomb* bomb = CreateObject<Bomb>(objects[0]->GetLocation());
				bomb->SetDirection(1.0f);

			}
		}
		else if (InputControl::GetKeyDown(KEY_INPUT_SPACE))   //爆弾を落とすボタンだけが押されていたら
		{
			CreateObject<Bomb>(objects[0]->GetLocation());   //真下に爆弾を落とす
		}
	}
	if (timecount->GetTcount() <= 0)
	{
		StopSoundMem(MainSE);   //メインSEの停止
	}
	
	
}


//描画処理
void Scene::Draw() const
{
	DrawExtendGraph(0, 0, 640,480,imageback, FALSE);   //背景の描画
	DrawExtendGraph(0,440, 40, 480, clockimage,FALSE);   //時計の描画
	//シーンに存在するオブジェクトの描画処理
	for (GameObject* obj : objects)
	{

		
		if (obj->flag == true)
		{
			obj->Draw();
		}
	}

	timecount->Draw();

	//メインのBGMが流れていなかったら
	if (CheckSoundMem(MainSE) != TRUE)
	{
		DrawExtendGraph(120, 100, 520, 300, Finishimage, TRUE);   //終了の文字の描画
		//PlaySoundMem(FinishSE, DX_PLAYTYPE_NORMAL, TRUE);   //終了SEの再生(再生したらESCキーがきかない)
	}
}

//終了処理
void Scene::Finalize()
{
	//動的配列が空なら処理を終了する
	if (objects.empty())
	{
		return;
	}

	//各オブジェクトを削除する
	for (GameObject* obj : objects)
	{
		obj->Finalize();
		delete obj;
	}

	//動的配列の解放
	objects.clear();
}

#ifdef D_PIVOT_CENTER


//当たり判定チェック処理（矩形の中心で当たり判定をとる）
void Scene::HitCheckObject(GameObject* a, GameObject* b)
{
	//2つのオブジェクトの距離を取得
	Vector2D diff = a->GetLocation() - b->GetLocation();

	//2つのオブジェクトの当たり判定の大きさを取得
	Vector2D box_size = (a->GetBoxSize() + b->GetBoxSize()) / 2.0f;

	//距離より大きさが大きい場合、Hit判定とする
	if ((fabs(diff.x) < box_size.x) && (fabsf(diff.y) < box_size.y))
	{
		if (a->GetType() == b->GetType())
		{
			return;
		}
		else
		{
			//当たったことをオブジェクトに通知する
			a->OnHitCollision(b);
			b->OnHitCollision(a);

			//Enemycountを増やす（最大敵出現数を10にするため）
			Enemycount++;
		}
	}
}

#else

//当たり判定チェック処理（左上頂点の座標から当たり判定計算を行う)
void Scene::HitCheckObject(GameObject* a, GameObject* b)
{
	//右下頂点座標を取得する
	Vector2D a_lower_right = a->GetLocation() + a->GetBoxSize();
	Vector2D b_lower_right = b->GetLocation() + b->GetBoxSize();

	//矩形Aと矩形Bの位置関係を調べる
	if ((a->GetLocation().x < b_lower_right.x) &&
		(a->GetLocation().y < b_lower_right.y) &&
		(a_lower_right.x > b->GetLocation().x) &&
		(a_lower_right.y > b->GetLocation().y))
	{
		//オブジェクトにたいしてHit判定を通知する
		a->OnHitCollision(b);
		b->OnHitCollision(a);
	}
}
#endif // D_PIVOT_CNETER
