#pragma once
#include"../common.h"
#include"EnemyBase.h"
static const float HGOBLIN_RADIUS = 60;

static const int HGOBLIN_HP = 250;

static const float HGOBLIN_SPEED = 3;

class CHGoblin :public CEnemyBase {
public:
private:


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

	float GetRadius() { return HGOBLIN_RADIUS; }
};