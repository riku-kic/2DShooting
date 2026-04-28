#pragma once

#include "../Base/Chara/CharaBase.h"

class Enemy : public CharaBase
{
public:

	Enemy(){}
	~Enemy(){}

	void Update() override;
	void Draw() override;
	void Init() override;
	void Release() override;
	void ImGuiUpdate();

	void GetPlayerBullet(Math::Vector2 _m_pos) { m_pBullet = _m_pos; }

	bool m_alive;

	Math::Vector2 m_pBullet ;

	Math::Vector2 m_pos;

private:

	KdTexture	m_tex;

	Math::Matrix m_mat;

	static const int m_move;

public:
	static Enemy& GetInstance()
	{
		static Enemy instance;
		return instance;
	}
};

#define ENEMY Enemy::GetInstance()