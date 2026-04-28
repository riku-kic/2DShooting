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

	bool m_alive;

private:

	KdTexture	m_tex;

	Math::Matrix m_mat;
	Math::Vector2 m_pos;

	static const int m_move;

};