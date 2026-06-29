#pragma once
#include"../common.h"
#include"EnemyBase.h"

static const float GOBLIN_RADIUS = 40;

static const int GOBLIN_HP = 175;

static const float GOBLIN_SPEED = 3;




class CGoblin :public CEnemyBase {
public:
private:
	


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

	float GetRadius() { return GOBLIN_RADIUS; }

};