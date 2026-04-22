#pragma once
#include "../Base/CharaBase.h"

class Player : public CharaBase
{
private:

	Player() {}
	~Player() { Release(); }

	void Update();
	void Draw();
	void Init();
	

public:

	void Release();

};