#include "Enemy.h"
#include "../Base/Chara/CharaBase.h"

void Enemy::Update()
{
	if (m_alive) {
		m_pos.x -= 5;

		if (m_pos.x < -680) {
			m_pos.x = 680;
		}

		float x =  m_pBullet.x - m_pos.x;
		float y =  m_pBullet.y - m_pos.y;
		float z = sqrt(x * x + y * y);

		if (z < 40) {
			m_alive = false;
		}

		m_mat = Math::Matrix::CreateTranslation(m_pos.x, m_pos.y, 0);
	}
}

void Enemy::Draw()
{
	if (m_alive) {
		SHADER.m_spriteShader.SetMatrix(m_mat);
		SHADER.m_spriteShader.DrawTex(&m_tex, Math::Rectangle(0, 0, 64, 64), 1.0f);
	}
}

void Enemy::Init()
{
	m_tex.Load("Texture/Enemy.png");
	m_pos = { 100,0 };
	m_pBullet = { 1280,1280 };
	m_alive = true;
}

void Enemy::Release()
{
	m_tex.Release();
}


void Enemy::ImGuiUpdate()
{
	float x = m_pos.x - m_pBullet.x;
	float y = m_pos.y - m_pBullet.y;
	float z = sqrt(x * x + y * y);

	ImGui::Text("Z : %f", z);
	ImGui::Text("m_pos.x : %f", m_pos.x);

}
