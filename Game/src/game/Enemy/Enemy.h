#pragma once
#include"../common.h"
#include"EnemyBase.h"
class CEnemy :public CEnemyBase {
private:

public:
	CEnemy();
	~CEnemy();
	virtual void Init();
	virtual void Load(int originHndl);
	virtual void Step();
	virtual void Draw();
	virtual void Exit();
};