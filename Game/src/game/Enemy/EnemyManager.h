#pragma once
#include"HGoblinManager.h"
#include"GoblinManager.h"
#include"EnemyManagerBase.h"
enum EnemyType {
	Gob,
	HGob,

	EnemyNum
};

class CEnemyManager {
private:
	CEnemyManagerBase* m_enemy[EnemyNum];

public:
	CEnemyManager();
	~CEnemyManager();

	void Init();

	void Load();

	void Step();

	void Draw();

	void Exit();

	void Update();

	void Request(VECTOR startpos, const vector<VECTOR>& path,EnemyType enemy);

	CGoblin& GetGoblin(int i);

	CHGoblin& GetHGoblin(int i);

	void Reset();

	bool IsAllDead();
};