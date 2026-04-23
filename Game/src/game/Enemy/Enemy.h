#pragma once
#include"../common.h"
#include"../../lib/Object/Object3D.h"
class CEnemyBase :public CObject3D {
private:
	void RequestEnemy();
public:
	CEnemyBase();
	~CEnemyBase();
	virtual void Init();
	virtual void Load();
	virtual void Step();
	virtual void Draw();
	virtual void Exit();
};