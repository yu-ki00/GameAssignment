#pragma once
#include"../common.h"
#include"EnemyBase.h"
static const float ENEMY_RADIUS = 40;

static const int ENEMY_HP = 200;

static const float ENEMY_SPEED = 3;


class CEnemy :public CEnemyBase {
public:
	enum tagEnemyState {
		NORMAL,
		FIRE,
		DAMAGE
	};
private:
	
	int m_hp;

	float m_speed;

	bool m_slow;

	tagEnemyState m_state;

	int m_fireTime;

	int m_damageTime;

	bool m_isKnock;

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

	void HitDamage();

	void IsFire();

	tagEnemyState GetState() { return m_state; }

	void KnockBack();
};