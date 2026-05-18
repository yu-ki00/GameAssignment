#pragma once
#include"../common.h"
#include"../../lib/Object/Object3D.h"
class CTrapBase :public CObject3D {
private:

public:
	CTrapBase();

	~CTrapBase();

	virtual void Init();

	virtual void Load(int originHndl);

	virtual void Step();

	virtual void Draw();

	virtual void Exit();
};