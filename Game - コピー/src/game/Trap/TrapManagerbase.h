#pragma once
#include<DxLib.h>

class CTrapManagerBase {
private:



public:
	virtual void Init() = 0;

	virtual void Load() = 0;

	virtual void Step() = 0;

	virtual void Draw() = 0;

	virtual void Exit() = 0;

	virtual void Update() = 0;

	virtual void Request(VECTOR pos, bool hit) = 0;
};