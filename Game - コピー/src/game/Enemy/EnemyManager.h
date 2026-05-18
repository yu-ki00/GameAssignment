#pragma once
#include"Enemy.h"
static const char ENEMY_MODEL_PATH[] = { "Data/Model/enemy/enemy.mv1" };
static const int ENEMY_NUM = 10;
static const int WAIT_TIME=60;
class CEnemyManager {
private:

	CEnemy m_enemy[ENEMY_NUM];

	int m_waitTime;

public:
	CEnemyManager();

	~CEnemyManager();

	void Init();

	void Load();

	void Step(VECTOR startpos,VECTOR endpos);

	void Draw();

	void Exit();

	void Update();

	CEnemy& GetEnemy(int i) { return m_enemy[i]; }

};