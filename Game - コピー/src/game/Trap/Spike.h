#pragma once
#include"../common.h"
#include"TrapBase.h"
#include"../../lib/Object/Object3D.h"
class CSpike :public CTrapBase {
private:

public:
	CSpike();

	~CSpike();

	int GetHndl() { return m_hndl; }

};