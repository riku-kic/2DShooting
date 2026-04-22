#pragma once

class CharaBase
{
protected:

	CharaBase() {}
	~CharaBase() { Release(); }

	void Update();
	void Draw();
	void Init();
	void Release();

public:

	KdTexture m_tex;
	Math::Matrix m_mat;
	Math::Vector2 m_pos;

};