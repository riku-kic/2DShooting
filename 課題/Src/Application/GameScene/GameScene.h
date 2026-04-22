#pragma once

class Player;

class GameScene
{
private:

	GameScene() {}
	~GameScene() { Release(); }

	void Update();
	void Draw();
	void Init();
	void Release();

public:



};