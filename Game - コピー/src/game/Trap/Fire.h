#pragma once
#include"../common.h"
#include"TrapBase.h"
#include"../../lib/Object/Object3D.h"
class CFire :public CTrapBase {
private:

	bool m_isFire;

	int m_coolTime;

public:
	CFire();

	~CFire();
	void Init();

	void Step(VECTOR pos);

	void Request(VECTOR pos);

	int GetHndl() { return m_hndl; }
};