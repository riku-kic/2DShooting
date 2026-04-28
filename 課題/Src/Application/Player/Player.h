#pragma once
#include "../Base/Chara/CharaBase.h"

// Player ‚Æ‘ŠŒİQÆ‚·‚é‚¾‚¯‚È‚ç‘O•ûéŒ¾‚Å\•ª
class PlayerBullet;

class Player : public CharaBase
{
public:

	Player() {}
	~Player() { Release(); }

	void Update()override;
	void Draw()override;
	void Init()override;
	void Release()override;

	Math::Vector2 SetPlayerPos(){ return m_pos; }

private:

	

	PlayerBullet* m_bullet;

	KdTexture m_tex;
	KdTexture m_playerHitBoxTex;

	Math::Matrix m_mat;
	Math::Matrix m_playerHitBoxMat;

	Math::Vector2 m_pos;
	//Math::Vector2 m_pos2;

	float m_delayTime;

	bool keyDown;



public:
	static Player& GetInstance()
	{
		static Player instance;
		return instance;
	}
};

#define PLAYER Player::GetInstance()