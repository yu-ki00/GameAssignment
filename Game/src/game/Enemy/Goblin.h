#pragma once
#include"../common.h"
#include"EnemyBase.h"

static const float GOBLIN_RADIUS = 40;

static const int GOBLIN_HP = 175;

static const float GOBLIN_SPEED = 3;




class CGoblin :public CEnemyBase {
public:
private:
	
	float m_hp;

	float m_speed;

	bool m_slow;

	int m_fireTime;

	int m_damageTime;

	bool m_isKnock;

	VECTOR m_knockPow;

	int m_knockTime;

	bool m_isDamage;

	bool m_isFire;

	bool m_isDeath;

	int m_pathIndex;

	vector<VECTOR> m_path;

public:

	CGoblin();
	~CGoblin();
	void Init();

	void Load(int originHndl);

	void Step();

	void Draw();

	void Exit();

	void Request(VECTOR pos);

	VECTOR GetCenter();

	void SubHp(int sub) { m_hp-=sub; }

	void SetSlow(bool slow) { m_slow = slow; }

	bool GetSlow() { return m_slow; }

	void HitDamage();

	void SetFire();

	void KnockBack(VECTOR vec);

	bool GetIsDamage() { return m_isDamage; }

	bool GetIsDeath() { return m_isDeath; }

	void Reset();

	void SetPath(const vector<VECTOR>& path);
};