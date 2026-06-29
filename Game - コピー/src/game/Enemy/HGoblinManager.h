#pragma once
#include"HobGoblin.h"
#include"EnemyManagerBase.h"

static const char HG_MODEL_PATH[] = { "Data/Model/enemy/enemy.mv1" };
static const int HG_NUM = 14;
static const int WAIT_TIME2 = 500;

class CHGManager:public CEnemyManagerBase {
private:

	CHGoblin m_hg[HG_NUM];

	int m_waitTime;

	int m_waveEnemy;

public:
	CHGManager();

	~CHGManager();

	void Init();

	void Load();

	void Step();

	void Draw();

	void Exit();

	void Update();

	CHGoblin& GetHGoblin(int i) { return m_hg[i]; }

	void Request(VECTOR startpos, const vector<VECTOR>& path);

	bool IsAllDead();

	void Reset();

	int GetEnemyNum() { return HG_NUM; }

	CEnemyBase* GetEnemy(int i);


};
