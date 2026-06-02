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

	virtual void Step(VECTOR pos);

	virtual void Draw();

	virtual void Exit();

	virtual void Update();

	virtual void Request(VECTOR pos);

	virtual void Reset();

	virtual void DrawA();
};