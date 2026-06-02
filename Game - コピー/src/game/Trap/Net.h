#pragma once
#include"../common.h"
#include"TrapBase.h"
#include"../../lib/Object/Object3D.h"
class CNet :public CTrapBase {
private:

public:
	CNet();

	~CNet();

	int GetHndl() { return m_hndl; }
};