#pragma once
#define D_PIVOT_CENTER

#include<vector>
#include"../Objects/GameObject.h"
#include"../Objects/Time.Score/timecount.h"
#include"../Objects/Enemys/EBomb.h"
#include"../Objects/Enemys/Enemy.h"


class Scene
{
private:
	std::vector<GameObject*>objects;

	Timecount*timecount;   //sceneでtimecountを呼び出せるように

	int imageback;   //背景の描画
	int clockimage;   //時計の描画
	int Finishimage;   //終了の描画

	int Enemycount;   //敵の生成数
	int count;   //時間経過

	int MainSE;   //ゲームメインSE
	int FinishSE;   //時間終了SE

	Vector2D EnemyBomb;   //敵の爆弾がプレイヤーに向かって飛んでいく
	Vector2D EBdirection;   //敵攻撃の位置座標

	//EBomb* ebomb;

public:
	Scene();
	~Scene();

	//初期化処理
	void Initialize();
	//更新処理
	void Update();
	//描画処理
	void Draw() const;
	//終了処理
	void Finalize();

	

private:
	//当たり判定チェック処理
	void HitCheckObject(GameObject* a, GameObject* b);

	//オブジェクト生成処理
	template <class T>
	T* CreateObject(const Vector2D& location)
	{
		//指定したクラスを生成する
		T* new_instance = new T();
		//GameObjectクラスを継承しているか確認
		GameObject* new_object = dynamic_cast<GameObject*>(new_instance);

		//エラーチェック
		if (new_object == nullptr)
		{
			delete new_instance;
			throw ("ゲームオブジェクトが生成できませんでした");
		}

		//初期化処理
		new_object->Initialize();
		//位置情報の設定
		new_object->SetLocation(location);

		//オブジェクトリストに追加
		objects.push_back(new_object);

		//インスタンスのポインタを返却
		return new_instance;
	}

};

