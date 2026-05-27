#pragma once
#include<DxLib.h>
#include"../../lib/Object/Object3D.h"

static const char CRYSTAL_PATH[] = { "Data/Model/field/start.mv1" };
class CCrystal:public CObject3D {
private:
	int m_hp = 30;
public:
	CCrystal();
	~CCrystal();

	void Init();

	void Load(VECTOR pos);

	void Step();

	void SubHp(int sub) { m_hp -= sub; }

	int GetHndl() { return m_hndl; }
};