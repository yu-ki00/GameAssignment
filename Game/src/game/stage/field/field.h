#pragma once
#include"../../../lib/Object/Object3D.h"
static const char FIELD_PATH[] = { "Data/Model/field/field.mv1" };
class CField :public CObject3D {
private:

public:
	CField();
	~CField();
	void Init();
	void Load();
	void Step();
	void Draw();
	void Exit();
	int GetHndl() { return m_hndl; }
};