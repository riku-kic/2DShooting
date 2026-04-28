#pragma once

#include "../../Base/Chara/CharaBase.h"

// forward
class Player;
class Enemy;

class PlayerBullet : public CharaBase
{
public:
	PlayerBullet() {  }
	~PlayerBullet() { Release(); }

	void Update() override;
	void Draw() override;
	void Init() override;
	void Release();

	void GetPlayerPos(Math::Vector2 _m_pos) { m_pos = _m_pos; }

	Player* m_player = nullptr;

	Enemy* m_enemy = nullptr;

	Math::Vector2 m_pos = { 0,0 };

	bool m_alive = false;
private:
	// 既存のプレイヤーインスタンスを参照する
	

	KdTexture m_tex;

	Math::Matrix m_mat;

	static const int mapHeight = 1280;
	static const int mapWidth = 720;
	static const int m_move = 10;

	
	// 他のメンバは必要に応じて維持してください


public:
	static PlayerBullet& GetInstance()
	{
		static PlayerBullet instance;
		return instance;
	}
};

#define P_BUL PlayerBullet::GetInstance()