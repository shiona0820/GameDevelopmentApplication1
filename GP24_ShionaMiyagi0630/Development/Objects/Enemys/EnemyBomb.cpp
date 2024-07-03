#include"EnemyBomb.h"
#include"DxLib.h"

//コンストラクタ
EnemyBomb::EnemyBomb() :animation_count(0), direction(0.0f)
{
	animation[0] = NULL;
	animation[1] = NULL;
	animation[2] = NULL;
	animation[3] = NULL;
}

//デストラクタ
EnemyBomb::~EnemyBomb()
{

}

//初期化処理
void EnemyBomb::Initialize()
{
	//画像の読み込み
	animation[0] = LoadGraph("Resource/images/EnemyBomb/1.png");
	animation[1] = LoadGraph("Resource/images/EnemyBomb/2.png");
	animation[2] = LoadGraph("Resource/images/EnemyBomb/3.png");
	animation[3] = LoadGraph("Resource/images/EnemyBomb/4.png");

	//エラーチェック
	if (animation[0] == -1 || animation[1] == -1 || animation[2] == -1 || animation[3] == -1)
	{
		throw("敵ボムの画像がありません\n");
	}

	//向きの設定
	radian = DX_PI_F / 2;

	//当たり判定の大きさ設定
	box_size = 64.0f;

	//初期化処理の設定
	image = animation[0];

	//初期進行方向の設定
	direction = Vector2D(0.0f, 1.0f);

	type = BOMB;
}

//更新処理
void EnemyBomb::Update()
{
	//移動処理
	Movement();
	//アニメーション制御
	AnimeControl();
}

//描画処理
void EnemyBomb::Draw() const
{
	if (flag == true)
	{
		__super::Draw();
	}


	//情報をもとに爆弾画像を描画する
	//DrawRotaGraphF(location.x, location.y, 1.0, radian, image, TRUE);

	//親クラスの描画処理を呼び出す

}

//終了時処理
void EnemyBomb::Finalize()
{
	//使用した画像を開放する
	DeleteGraph(animation[0]);
	DeleteGraph(animation[1]);
	DeleteGraph(animation[2]);
	DeleteGraph(animation[3]);
}

//当たり判定通知処理
void EnemyBomb::OnHitCollision(GameObject* hit_object)
{
	//当たった時の処理
	//敵にあたったら、敵の当たり判定を消す
	flag = false;
	Finalize();

}

//移動処理
void EnemyBomb::Movement()
{
	//進行方向に向かって、位置座標を変更する
	location += direction;
}

//アニメーション制御
void EnemyBomb::AnimeControl()
{
	//フレームカウントを加算する
	animation_count++;

	//60フレーム目に到達したら,または敵に当たった時
	if (animation_count >= 300)
	{
		//画像の切り替え
		if (image == animation[0])
		{
			radian = 0.0;
			direction = 0.0f;
			image = animation[1];
		}
		
	}
}