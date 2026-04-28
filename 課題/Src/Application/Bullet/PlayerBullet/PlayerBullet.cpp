#include "PlayerBullet.h"
#include "../../Player/Player.h"

void PlayerBullet::Update()
{

	m_pos.y += m_move;
		
	if (m_pos.y > mapWidth && m_pos.x > mapHeight || m_pos.y < -720 && m_pos.x > mapHeight || m_pos.y > mapWidth && m_pos.x > -1280) 
	{			
		m_alive = false;
	}
	else if (m_pos.y < -720 && m_pos.x > mapHeight)
	{
		m_alive = false;
	}
	
		m_mat = Math::Matrix::CreateTranslation(m_pos.x, m_pos.y, 0);
}

void PlayerBullet::Draw()
{
	if (m_alive) {
		SHADER.m_spriteShader.SetMatrix(m_mat);
		SHADER.m_spriteShader.DrawTex(&m_tex, Math::Rectangle(0, 0, 15, 15), 1.0f);
	}

}

void PlayerBullet::Init()
{
	// 新しく生成せず、既存のプレイヤーインスタンスを参照する
	m_player = &PLAYER;

	m_pos = m_player->SetPlayerPos();

	m_tex.Load("Texture/Bullet.png");

	m_alive = true;
}

void PlayerBullet::Release()
{
	m_tex.Release();
}