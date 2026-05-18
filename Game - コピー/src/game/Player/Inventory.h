#pragma once
#include<DxLib.h>
#include"../Trap/TrapManager.h"
class CInventory {
private:
	int m_gold;
	TrapType m_trapNumber;
public:
	void Init();

	void Load();

	void Step();

	void Draw();

	void Exit();

	void SubGold();
};