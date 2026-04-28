#pragma once

#include <vector>
#include <memory>

class CharaBase;
class CharaScene;
class Player; // 前方宣言はそのまま

class GameScene
{
public:

	GameScene() {}
	~GameScene() { Release(); }

	void Update();
	void Draw();
	void Init();
	void Release();

private:
	std::vector<std::shared_ptr<CharaBase>> m_objList;

	// 現在のプレイヤーインスタンスを保持しておく
	std::shared_ptr<Player> m_player; // 有効化

	float m_delayTime;

	bool keyDown;
	bool m_BAlive;

	static const int BulletNum = 70;

	KdTexture m_tex;
	KdTexture m_playerHitBoxTex;

	Math::Matrix m_mat;
	Math::Matrix m_playerHitBoxMat;

	Math::Vector2 m_pos = { };

};