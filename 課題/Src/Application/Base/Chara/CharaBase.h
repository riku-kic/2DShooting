#pragma once

class CharaBase
{
public:

	CharaBase() {}
	virtual~CharaBase() {}

	virtual void Update();
	virtual void Draw();
	virtual void Init();
	virtual void Release();

protected:

	KdTexture m_tex;
	Math::Matrix m_mat;
	Math::Vector2 m_pos;

};