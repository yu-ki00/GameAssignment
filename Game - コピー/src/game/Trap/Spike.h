#pragma once
#include"../common.h"
#include"../../lib/Object/Object3D.h"
class CSpike :public CObject3D {
private:

public:
	CSpike();

	~CSpike();

	void Init();

	void Load(int originHndl);

	void Step();

	void Draw();

	void Exit();
};