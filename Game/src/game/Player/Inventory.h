#pragma once
#include<DxLib.h>
#include"../Trap/TrapManager.h"
static const int NEED_GOLD[TrapNum]{ 100,200 };

static const char TRAP_GRAPH_PATH[][255]{ "Data/graph/Spike.png","Data/graph/Net.png","Data/graph/Fire.png" };
class CInventory {
private:
	int m_gold;
	TrapType m_trapNumber;
	struct Trap{
		VECTOR m_pos;
		int m_hndl;
	};

	Trap m_trap[TrapNum];
public:
	void Init();

	void Load();

	void Step();

	void Draw();

	void Exit();

	void SubGold();

	void AddGold();

	int GetGold() { return m_gold; }

	TrapType GetTrap() { return m_trapNumber; }

	void Reset();
};