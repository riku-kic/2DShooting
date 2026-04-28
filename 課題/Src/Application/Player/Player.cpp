#include "Player.h"
#include "../Bullet/PlayerBullet/PlayerBullet.h"

void Player::Update()
{
	// プレイヤーの移動
	{
		//キーボード
		{
			if (GetAsyncKeyState(VK_UP) & 0x8000)
			{
				m_pos.y += 8.0f;

				if (GetAsyncKeyState(VK_LCONTROL) & 0x8000)
				{
					m_pos.y -= 4.0f;
				}

			}

			if (GetAsyncKeyState(VK_DOWN) & 0x8000)
			{
				m_pos.y -= 8.0f;

				if (GetAsyncKeyState(VK_LCONTROL) & 0x8000)
				{
					m_pos.y += 4.0f;
				}
			}

			if (GetAsyncKeyState(VK_LEFT) & 0x8000)
			{
				m_pos.x -= 8.0f;

				if (GetAsyncKeyState(VK_LCONTROL) & 0x8000)
				{
					m_pos.x += 4.0f;
				}
			}

			if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
			{
				m_pos.x += 8.0f;

				if (GetAsyncKeyState(VK_LCONTROL) & 0x8000)
				{
					m_pos.x -= 4.0f;
				}
			}

		}

		//xboxコン
		{
			if (GetAsyncKeyState(VK_GAMEPAD_LEFT_THUMBSTICK_UP) & 0x8000) {

				m_pos.y += 8.0f;

				if (GetAsyncKeyState(VK_GAMEPAD_X) & 0x8000)
				{
					m_pos.y -= 4.0f;
				}

			}

			if (GetAsyncKeyState(VK_GAMEPAD_LEFT_THUMBSTICK_DOWN) & 0x8000) {

				m_pos.y -= 8.0f;

				if (GetAsyncKeyState(VK_GAMEPAD_X) & 0x8000)
				{
					m_pos.y += 4.0f;
				}

			}

			if (GetAsyncKeyState(VK_GAMEPAD_LEFT_THUMBSTICK_LEFT) & 0x8000) {

				m_pos.x -= 8.0f;

				if (GetAsyncKeyState(VK_GAMEPAD_X) & 0x8000)
				{
					m_pos.x += 4.0f;
				}

			}

			if (GetAsyncKeyState(VK_GAMEPAD_LEFT_THUMBSTICK_RIGHT) & 0x8000) {

				m_pos.x += 8.0f;

				if (GetAsyncKeyState(VK_GAMEPAD_X) & 0x8000)
				{
					m_pos.x -= 4.0f;
				}

			}

		}

	}

	//m_bullet->GetPlayerPos(m_pos);

	m_mat = Math::Matrix::CreateTranslation(m_pos.x, m_pos.y, 0);
	m_playerHitBoxMat = Math::Matrix::CreateTranslation(m_pos.x, m_pos.y - 5, 0);
}

void Player::Draw()
{
	SHADER.m_spriteShader.SetMatrix(m_mat);
	SHADER.m_spriteShader.DrawTex(&m_tex, Math::Rectangle(0, 0, 64, 64),1.0f);

	SHADER.m_spriteShader.SetMatrix(m_playerHitBoxMat);
	SHADER.m_spriteShader.DrawTex(&m_playerHitBoxTex, Math::Rectangle(0, 0, 11, 13), 1.0f);

	m_delayTime = 0;

	//SHADER.m_spriteShader.DrawString(0, 0, "Hello World", Math::Vector4(1, 1, 0, 1));
}

void Player::Init()
{
	m_bullet = &P_BUL;

	m_tex.Load("Texture/Player.png");
	m_playerHitBoxTex.Load("Texture/PlayerHitBox.png");
	m_pos = { 0,-250 };

	keyDown = false;

}

void Player::Release()
{
	m_tex.Release();
	m_playerHitBoxTex.Release();
}