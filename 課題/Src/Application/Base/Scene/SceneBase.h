#pragma once

class SceneBase {
public:
	SceneBase() {};
	~SceneBase() { Release(); };

	void Update();
	void Init();
	void Draw();
	void Release();

protected:

	KdTexture m_tex;
	Math::Matrix m_mat;
	Math::Vector2 m_pos;

};