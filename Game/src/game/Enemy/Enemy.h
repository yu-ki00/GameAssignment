#pragma once
#include"../common.h"
#include"EnemyBase.h"
static const float ENEMY_RADIUS = 100;

static const int ENEMY_HP = 200;
class CEnemy :public CEnemyBase {
private:
	int m_hp;
public:
	CEnemy();
	~CEnemy();
	void Init();
	void Load(int originHndl);
	void Step(VECTOR endpos);
	void Draw();
	void Exit();
	void Request(VECTOR pos);
	VECTOR GetCenter();
	void SubHp(int sub) { m_hp-=sub; }
};