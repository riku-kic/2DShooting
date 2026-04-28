#include "GameScene.h"
#include "../../Enemy/Enemy.h"
#include "../../Player/Player.h"
#include "../../Bullet/PlayerBullet/PlayerBullet.h"

void GameScene::Update()
{
	PLAYER.GetInstance().Update();

	if (!keyDown) {
		keyDown = true;

		if (GetAsyncKeyState('Z') & 0x8000)
		{
			m_delayTime--;
			if (m_delayTime <= 0)
			{
				for (int i = 0; i < BulletNum; ++i)
				{
					std::shared_ptr<PlayerBullet> playerBullet;
					playerBullet = std::make_shared<PlayerBullet>();	// インスタンス生成
					playerBullet->Init();								// 初期

					playerBullet->m_pos = PLAYER.GetInstance().SetPlayerPos(); // 初期位置コピー
					// 必要なら生存フラグも立てる
					playerBullet->m_alive = true;

					std::shared_ptr<Enemy> enemy;
					enemy = std::make_shared<Enemy>();	// インスタンス生成
					enemy->m_pBullet = playerBullet->m_pos;

					m_objList.push_back(playerBullet);					// リストへ追加
					m_objList.push_back(enemy);					// リストへ追加

				}
				m_delayTime = 5;
			}
		}
		
	}
	else 
	{
		keyDown = false;
			
	}


		// 全オブジェクトの更新を呼ぶ
		for (int i = 0; i < m_objList.size(); ++i)
		{
			m_objList[i]->Update();
		}
}

void GameScene::Draw()
{
	// 全オブジェクトの描画関数を呼ぶ
	for (int i = 0; i < m_objList.size(); ++i)
	{
		m_objList[i]->Draw();
	}

	PLAYER.GetInstance().Draw();
}

void GameScene::Init()
{
	m_BAlive = false;

	PLAYER.GetInstance().Init();

	std::shared_ptr<Enemy> enemy;
	enemy = std::make_shared<Enemy>();	// インスタンス生成
	enemy->Init();	// 初期
	m_objList.push_back(enemy);					// リストへ追加


	// 追加：シーンが保持する共有プレイヤー参照をセット
	//m_player = player;
	keyDown = false;
}

void GameScene::Release()
{
	PLAYER.GetInstance().Release();
}