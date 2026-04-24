#pragma once
#include "../Base/Chara/CharaBase.h"

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
	KdTexture m_bulletTex;
	KdTexture m_playerHitBoxTex;

	Math::Matrix m_mat;
	Math::Matrix m_bulletMat;
	Math::Matrix m_playerHitBoxMat;

	Math::Vector2 m_pos = { };
	Math::Vector2 m_bulletPos = {};

};