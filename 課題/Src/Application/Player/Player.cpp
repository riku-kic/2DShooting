#include "Player.h"

void Player::Update()
{

}

void Player::Draw()
{
	SHADER.m_spriteShader.SetMatrix(m_mat);
	SHADER.m_spriteShader.DrawTex(&m_tex, Math::Rectangle(0, 0, 64, 64),1.0f);
}

void Player::Init()
{
	m_tex.Load("Texture/player.png");
	m_pos = { 0,0 };
	m_mat = Math::Matrix::CreateTranslation(0, 0, 0);
}


void Player::Release()
{
	m_tex.Release();
}