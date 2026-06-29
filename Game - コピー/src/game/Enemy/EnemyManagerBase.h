#pragma once
#include<DxLib.h>
#include<vector>
using namespace std;
static const int ENEMY_NUM[2] = { 14 ,14 };
class CEnemyManagerBase {
private:

public:
	virtual void Init() = 0;

	virtual void Load() = 0;

	virtual void Step() = 0;

	virtual void Draw() = 0;

	virtual void Exit() = 0;

	virtual void Update() = 0;

	virtual void Request(VECTOR startpos, const vector<VECTOR>& path) = 0;

	virtual bool IsAllDead() = 0;

	virtual void Reset() = 0;

	virtual int GetEnemyNum() = 0;

	virtual CEnemyBase* GetEnemy(int i) = 0;

};