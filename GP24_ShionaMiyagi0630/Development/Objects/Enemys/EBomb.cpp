#include"EBomb.h"
#include"DxLib.h"

#include"../../Utility/InputControl.h"
#include"../GameObject.h"

//コンストラクタ
EBomb::EBomb() :animation_count(0), direction(0.0f)
{
	animation[0] = NULL;
	animation[1] = NULL;
	animation[2] = NULL;
	animation[3] = NULL;

}

//デストラクタ
EBomb::~EBomb()
{

}

//初期化処理
void EBomb::Initialize()
{
	//画像の読み込み
	//animation[0] = LoadGraph("Resource/images/EnemyBullet/1.png");
	//animation[1] = LoadGraph("Resource/images/EnemyBullet/eff1.png");
	//animation[2] = LoadGraph("Resource/images/EnemyBullet/eff12.png");
	//animation[3] = LoadGraph("Resource/images/EnemyBullet/eff13.png");

	////エラーチェック
	//if (animation[0] == -1 || animation[1] == -1 || animation[2] == -1 || animation[3] == -1)
	//{
	//	throw("敵ボムの画像がありません\n");
	//}

	//向きの設定
	radian = DX_PI_F / 2;

	//当たり判定の大きさ設定
	box_size = 64.0f;

	//初期化処理の設定
	image = animation[0];

	//初期進行方向の設定
	direction = Vector2D(0.0f, -1.0f);
	
}

//更新処理
void EBomb::Update()
{
	//移動処理
	Movement();
	//アニメーション制御
	AnimationControl();


}

//描画処理
void EBomb::Draw() const
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
void EBomb::Finalize()
{
	//使用した画像を開放する
	DeleteGraph(animation[0]);
	DeleteGraph(animation[1]);
	DeleteGraph(animation[2]);
	DeleteGraph(animation[3]);
}

//当たり判定通知処理
void EBomb::OnHitCollision(GameObject* hit_object)
{
	//当たった時の処理
	//敵にあたったら、敵の当たり判定を消す
	flag = false;
	Finalize();
	//direction = 0.0f;

	////使用した画像を開放する
	//DeleteGraph(animation[0]);
	//DeleteGraph(animation[1]);
	//DeleteGraph(animation[2]);
	//DeleteGraph(animation[3]);
}

//移動処理
void EBomb::Movement()
{
	//進行方向に向かって、位置座標を変更する
	location += direction;
}

//アニメーション制御
void EBomb::AnimationControl()
{
	//フレームカウントを加算する
	animation_count++;

}

//弾の進行方向 atan=タンジェントの逆三角形
void EBomb::SetDirection(float x)
{
	direction.x = x;
	Vector2D temp = location - (location - direction);
	radian = atan2f(temp.y, temp.x);
}
