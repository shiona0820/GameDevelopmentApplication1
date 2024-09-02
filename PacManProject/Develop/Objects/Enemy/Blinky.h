#pragma once

#include "EnemyBase.h"

class Blinky : public EnemyBase
{
private:
	std::vector<int> bmove_animation;   //移動のアニメーション画像

public:
	Blinky();   //コンストラクタ
	~Blinky();  //デストラクタ

	virtual void Initialize() override;                                //初期化処理
	virtual void Update(float delta_second) override;                  //更新処理
	virtual void Draw(const Vector2D& screen_offset) const override;   //描画処理
	virtual void Finalize() override; //終了処理
};

