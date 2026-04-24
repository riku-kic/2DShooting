#pragma once

class PlayerBullet
{
public:
	PlayerBullet(){}
	~PlayerBullet() { Release(); }

	void Init();
	void Update();
	void Draw();
	void Release();

	void SetPlayerPos(Math::Vector2 _pos) { m_pos = _pos; }

private:
	KdTexture m_tex;

	Math::Matrix m_mat;

	Math::Vector2 m_pos = {};

	bool alive;

	static const int mapHeght = 1280;
	static const int mapWidth = 720;

// ƒVƒ“ƒOƒ‹ƒgƒ“
private:


public:
	static PlayerBullet& GetInstance()
	{
		static PlayerBullet instance;
		return instance;
	}
};

#define P_BLT PlayerBullet::GetInstance()