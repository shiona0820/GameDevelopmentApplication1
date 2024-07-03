#include"WingEnemy.h"
#include"DxLib.h"

//コンストラクタ
WingEnemy::WingEnemy() :animation_count(0)
{
	animation[0] = NULL;
	animation[1] = NULL;
}

//デストラクタ
WingEnemy::~WingEnemy()
{

}

//初期化処理
void WingEnemy::Initialize()
{
	//画像の読み込み
	animation[0] = LoadGraph("Resource/images/WingEnemy/1.png");
	animation[1] = LoadGraph("Resource/images/WingEnemy/2.png");

	//エラーチェック
	if (animation[0] == -1 || animation[1] == -1)
	{
		throw("WingEnemyの画像がありません\n");
	}

	//向きの設定
	radian = 0.0;

	//当たり判定の大きさを設定
	box_size = 64.0f;

	//初期化処理の設定
	image = animation[0];

	//初期進行方向の設定
	direction = Vector2D(1.0f, 0.0f);

	flip_flag = FALSE;

}

//更新処理
void WingEnemy::Update()
{
	//移動処理
	Movement();
	//アニメーション制御
	AnimeControl();

}

//描画処理
void WingEnemy::Draw() const
{
	//反転グラフ
	int flip_flag = FALSE;

	//進行方向によって、反転状態を決定する
	if (direction.x > 0.0f)
	{
		flip_flag = FALSE;
	}
	else
	{
		flip_flag = TRUE;
	}

	//情報を基にハコテキ画像を描画する
	DrawRotaGraphF(location.x, location.y, 1.0, radian, image, TRUE, flip_flag);

	//親クラスの描画処理を呼び出す
	__super::Draw();

}

//終了時処理
void WingEnemy::Finalize()
{
	//使用した画像を開放する
	DeleteGraph(animation[0]);
	DeleteGraph(animation[1]);
}


//当たり判定通知処理
void WingEnemy::OnHitCollision(GameObject* hit_object)
{
	//当たった時の処理
	flag = false;
	Finalize();
}



//移動処理
void WingEnemy::Movement()
{
	//画面端に到達したら、進行方向を反転する
	if (((location.x + direction.x) < box_size.x) ||
		(640.0f - box_size.x) < (location.x + direction.x))
	{
		//端に到達したら移動方向が跳ね返る
		direction.x = -direction.x;


		//描画左右も替える
		if (direction.x > 0.0f)
		{
			flip_flag = FALSE;
		}
		else
		{
			flip_flag = TRUE;
		}
	}


	//direction.x *= -1.0f;
	//進行方向に向かって、位置情報を変更する
	location += direction;
}


//アニメーション制御
void WingEnemy::AnimeControl()
{
	//フレームカウントを加算する
	animation_count++;

	//60フレーム目に達成したら
	if (animation_count >= 60)
	{
		//カウントのリセット
		animation_count = 0;
		{
			//画像の切り替え
			if (image == animation[0])
			{
				image = animation[1];
			}
			else
			{
				image = animation[0];
			}
		}
	}

}


