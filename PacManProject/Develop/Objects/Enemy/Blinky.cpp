#include "Blinky.h"

#include"DxLib.h"

#include"EnemyBase.h"
#include"../../Utility/ResourceManager.h"
#include"DxLib.h"

#include"../Player/Player.h"

#define D_ENEMY_SPEED (100.0f)



Blinky::Blinky() :
	bmove_animation()
{
	
}

Blinky::~Blinky()
{

}

void Blinky::Initialize()
{
	// �A�j���[�V�����摜�̓ǂݍ���
	ResourceManager* rm = ResourceManager::GetInstance();
	bmove_animation = rm->GetImages("Resource/Images/monster.png", 20, 20, 1, 32, 32);

}

void Blinky::Update(float delta_second)
{
}

void Blinky::Draw(const Vector2D& screen_offset) const
{
	
}

void Blinky::Finalize()
{
}
