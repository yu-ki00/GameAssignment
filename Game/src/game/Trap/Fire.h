#pragma once
#include"../common.h"
#include"TrapBase.h"
#include"../../lib/Object/Object3D.h"
class CFire :public CTrapBase {
private:

public:
	CFire();

	~CFire();

	int GetHndl() { return m_hndl; }
};