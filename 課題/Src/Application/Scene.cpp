#include "main.h"
#include "Scene.h"
#include "IncPath/IncPath.h"

void Scene::Draw2D()
{
	m_gameScene->Draw();

	//m_player->Draw();
	 
	// 文字列表示
	//SHADER.m_spriteShader.DrawString(0, 0, "Hello World", Math::Vector4(1, 1, 0, 1));
	
}

void Scene::Update()
{
	m_gameScene->Update();
	
}

void Scene::Init()
{
	/*m_player = std::make_shared<Player>();
	m_player->Init();*/

	m_gameScene = std::make_shared<GameScene>();
	m_gameScene->Init();

	//PlayerBullet::GetInstance().Init();

	// 画像の読み込み処理
	//charaTex.Load("Texture/Player.png");

	matrix = Math::Matrix::CreateTranslation(0, 0, 0);
}

void Scene::Release()
{
	// 画像の解放処理
	charaTex.Release();
	m_gameScene->Release();
}

void Scene::ImGuiUpdate()
{
	return;

	ImGui::SetNextWindowPos(ImVec2(20, 20), ImGuiSetCond_Once);
	ImGui::SetNextWindowSize(ImVec2(200, 100), ImGuiSetCond_Once);

	// デバッグウィンドウ
	if (ImGui::Begin("Debug Window"))
	{
		ImGui::Text("FPS : %d", APP.m_fps);
	}
	ImGui::End();
}
