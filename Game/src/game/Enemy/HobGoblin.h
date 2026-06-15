#pragma once
#include"../common.h"
#include"EnemyBase.h"
static const float HGOBLIN_RADIUS = 40;

static const int HGOBLIN_HP = 250;

static const float HGOBLIN_SPEED = 3;

class CHGoblin :public CEnemyBase {
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

	CHGoblin();
	~CHGoblin();
	void Init();

	void Load(int originHndl);

	void Step();

	void Draw();

	void Exit();

	void Request(VECTOR pos);

	VECTOR GetCenter();

	void Reset();
};