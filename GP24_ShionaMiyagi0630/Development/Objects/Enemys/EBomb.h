#pragma once
#include "../GameObject.h"
#include"Enemy.h"

#include <vector>

class EBomb : public GameObject
{
private:
	int animation[4];   //アニメーション
	int animation_count;   //アニメーションの時間
	Vector2D direction;   //進行方向

public:
	EBomb();
	~EBomb();

	//初期化処理
	virtual void Initialize() override;
	//更新処理
	virtual void Update() override;
	//描画処理
	virtual void Draw() const override;
	//終了処理
	virtual void Finalize() override;

	//当たり判定通知処理
	virtual void OnHitCollision(GameObject* hit_object) override;

private:
	//移動処理
	void Movement();
	//アニメーション制御
	void AnimationControl();

	void SetDirection(float x);

};

