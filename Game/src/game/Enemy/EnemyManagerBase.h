#pragma once
#include<DxLib.h>
#include<vector>
using namespace std;
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

};