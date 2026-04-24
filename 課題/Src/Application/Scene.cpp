#include "main.h"
#include "Scene.h"
//#include "IncPath/IncPath.h"
#include "Player/Player.h"

void Scene::Draw2D()
{

	//SHADER.m_spriteShader.SetMatrix(matrix);
	//SHADER.m_spriteShader.DrawTex(&charaTex, Math::Rectangle(0, 0, 64, 64), 1.0f);
	
	m_player->Draw();


	// 文字列表示
	//SHADER.m_spriteShader.DrawString(0, 0, "Hello World", Math::Vector4(1, 1, 0, 1));
	
}

void Scene::Update()
{
	m_player->Update();
}

void Scene::Init()
{
	m_player = std::make_shared<Player>();
	m_player->Init();

	// 画像の読み込み処理
	//charaTex.Load("Texture/Player.png");

	matrix = Math::Matrix::CreateTranslation(0, 0, 0);
}

void Scene::Release()
{
	// 画像の解放処理
	charaTex.Release();
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
