#pragma once
#include"../common.h"
#include"TrapBase.h"
#include"../../lib/Object/Object3D.h"
class CNet :public CTrapBase {
private:

public:
	CNet();

	~CNet();

	void Init();

	void Load(int originHndl);

	void Step();

	void Draw();

	void Update();

	void Exit();

	int GetHndl() { return m_hndl; }
	void Request(VECTOR pos);
};