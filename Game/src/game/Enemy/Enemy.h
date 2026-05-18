#pragma once
#include"../common.h"
#include"EnemyBase.h"
static const float ENEMY_RADIUS = 100;

static const int ENEMY_HP = 200;

static const float ENEMY_SPEED = 3;
class CEnemy :public CEnemyBase {
private:
	enum tagState {
		NORMAL,
		FIRE,
		DAMAGE
	};
	int m_hp;

	float m_speed;

	bool m_slow;
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

	void SetSlow(bool slow) { m_slow = slow; }

	bool GetSlow() { return m_slow; }
};