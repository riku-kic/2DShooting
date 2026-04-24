#pragma once

class Player;

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



};