#include "PlayerBullet.h"

void PlayerBullet::Update()
{
	if (alive)
	{
		m_pos.y += 5;

		if (m_pos.y > 720 && m_pos.x > 1280) {
			alive = false;
		}
		else if (m_pos.y < -720 && m_pos.x > 1280)
		{
			alive = false;
		}
	}

	m_mat = Math::Matrix::CreateTranslation(m_pos.x, m_pos.y, 0);
}

void PlayerBullet::Draw()
{
	if (alive) {
		SHADER.m_spriteShader.SetMatrix(m_mat);
		SHADER.m_spriteShader.DrawTex(&m_tex, Math::Rectangle(0, 0, 15, 15), 1.0f);
	}

}

void PlayerBullet::Init()
{
	m_tex.Load("Texture/Bullet.png");
	alive = false;
}

void PlayerBullet::Release()
{
	m_tex.Release();
}