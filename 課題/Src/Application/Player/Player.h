#pragma once
#include "../Base/Chara/CharaBase.h"
#include "../Bullet/PlayerBullet/PlayerBullet.h"

class PlayerBullet;

class Player : public CharaBase
{
public:

	Player() {}
	~Player() { Release(); }

	void Update()override;
	void Draw()override;
	void Init()override;
	

private:

	void Release()override;

	KdTexture m_tex;
	KdTexture m_playerHitBoxTex;

	Math::Matrix m_mat;
	Math::Matrix m_playerHitBoxMat;

	Math::Vector2 m_pos = { };

	static const int BulletNum = 30;

	PlayerBullet* m_bullet[BulletNum];

public:
	static Player& GetInstance()
	{
		static Player instance;
		return instance;
	}
};

#define PLAYER Player::GetInstance()