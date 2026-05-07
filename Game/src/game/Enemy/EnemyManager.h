#pragma once
#include"Enemy.h"
static const char ENEMY_MODEL_PATH[] = { "Data/Model/trap/spike.mv1" };
static const int ENEMY_NUM = 10;
class CEnemyManager {
private:

	CEnemy m_enemy[ENEMY_NUM];

public:
	CEnemyManager();

	~CEnemyManager();

	void Init();

	void Load();

	void Step();

	void Draw();

	void Exit();

	void Update();

	void Request(VECTOR pos, bool hit);
};