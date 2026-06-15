#pragma once
#include"Goblin.h"
#include"EnemyManagerBase.h"
static const char GOBLIN_MODEL_PATH[] = { "Data/Model/enemy/enemy.mv1" };
static const int GOBLIN_NUM = 14;
static const int WAIT_TIME=500;

class CGoblinManager:public CEnemyManagerBase {
private:

	CGoblin m_goblin[GOBLIN_NUM];

	int m_waitTime;

	int m_waveEnemy;

public:
	CGoblinManager();

	~CGoblinManager();

	void Init();

	void Load();

	void Step();

	void Draw();

	void Exit();

	void Update();

	CGoblin& GetGoblin(int i) { return m_goblin[i]; }

	void Request(VECTOR startpos, const vector<VECTOR>& path);

	bool IsAllDead();

	void Reset();

};