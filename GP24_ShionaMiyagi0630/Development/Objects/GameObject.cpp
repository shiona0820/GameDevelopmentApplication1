#include "GameObject.h"
#include "Bomb.h"

#define D_PIVOT_CENTER
#include"DxLib.h"




//コンストラクタ
GameObject::GameObject() : flag(true), flip_flag(FALSE),
	scale(0.0),
	radian(0.0),
	image(0),
	sound(0),
	box_size(0.0f)
	
{
}

//デストラクタ
GameObject::~GameObject()
{

}

//初期化処理
void GameObject::Initialize()
{

	

}

//更新処理
void GameObject::Update()
{

}

//描画処理
void GameObject::Draw() const
{
	// 当たり判定の可視化
#ifdef D_PIVOT_CENTER
		Vector2D tl = location - (box_size / 2.0f);
	Vector2D br = location + (box_size / 2.0f);

	DrawBoxAA(tl.x, tl.y, br.x, br.y, GetColor(255, 0, 0), FALSE);
#else
		Vector2D tl = location;
	Vector2D br = location + box_size;

	DrawBoxAA(tl.x, tl.y, br.x, br.y, GetColor(255, 0, 0), FALSE);
#endif //D_PIVOT_CENTER

	//情報をもとに爆弾画像を描画する
	DrawRotaGraphF(location.x, location.y, 1.0, radian, image, TRUE, flip_flag);

	
}

//終了時処理
void GameObject::Finalize()
{

}

//当たり判定通知処理
void GameObject::OnHitCollision(GameObject* hit_object)
{
	//当たった時に行う処理
	flag = FALSE;
}

//位置情報取得処理
Vector2D GameObject::GetLocation() const
{
	return this->location;
}

//位置情報設定処理
void GameObject::SetLocation(const Vector2D& location)
{
	this->location = location;
}

//BoxSizeの大きさの取得
Vector2D GameObject::GetBoxSize() const
{
	return box_size;
}

//自身のタイプの取得処理
int GameObject::GetType()
{
	//自分のタイプを参照します
	return this->type;
}

//画像を斜めにするよう
void GameObject::SetRadian(double radian)
{
	this->Bombradian = radian;
}

