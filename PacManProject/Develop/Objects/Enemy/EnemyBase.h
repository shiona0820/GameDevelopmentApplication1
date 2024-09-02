#pragma once

#include"../GameObject.h"
#include"../../Utility/StageData.h"

//エネミー状態
enum eEnemystate
{
	ENEMY_MOVE,       //縄張り状態
	ENEMY_TRACKING,   //追跡状態
	ENEMY_IJIKE,      //いじけ状態
	ENEMY_EYE,       //めだま状態
};

//エネミーベースクラス
class EnemyBase : public GameObject
{
private:
	//進行方向状態
	enum eDirectionState : unsigned char
	{
		UP,
		RIGHT,
		DOWN,
		LEFT,
	};

private:
	std::vector<int> Emove_animation;   //移動のアニメーション画像
	std::vector<int> eye_animation;  //めだまのアニメーション画像
	Vector2D old_location;             //前回のlocation
	Vector2D velocity;						// 移動量
	eEnemystate enemy_state;           //エネミー状態
	eDirectionState now_direction_state;// 現在進行方向状態
	eDirectionState next_direction_state;// 次回進行方向状態
	float animation_time;					// アニメーション時間
	int animation_count;					// アニメーション添字
	int idle_animation_count;          //いじけアニメーション添え字
	ePanelID old_panel;						// 前回パネル情報
	bool is_destroy;						// 死んだ状態になったか？

	//移動アニメーションの順番
	const int animation_num[2] = { 0,1, };

public:
	EnemyBase();   //コンストラクタ
	~EnemyBase();  //デストラクタ

	virtual void Initialize() override;   //初期化処理
	virtual void Update(float delta_second) override;       //更新処理
	virtual void Draw(const Vector2D& screen_offset) const override;         //描画処理
	virtual void Finalize() override;     //終了処理

	//当たり判定通知処理
	virtual void OnHitCollision(GameObjectBase* hit_object) override;
public:
	/// <summary>
	/// エネミーの状態を取得する
	/// </summary>
	/// <returns>エネミーの状態</returns>
	eEnemystate GetEnemyState() const;

	/// <summary>
	/// エネミーが死んだかどうか確認する
	/// </summary>
	/// <returns>エネミーの状態</returns>
	bool GetDestroy() const;

private:
	/// <summary>
	/// 移動処理
	/// </summary>
	/// <param name="delta_second">1フレーム当たりの時間</param>
	void Movement(float delta_second);
	/// <summary>
	/// アニメーション制御
	/// </summary>
	/// <param name="delta_second">1フレーム当たりの時間</param>
	void AnimationControl(float delta_second);

};
