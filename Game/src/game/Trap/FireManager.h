#pragma once
#include"TrapBase.h"
#include"Fire.h"
#include"TrapManagerbase.h"

static const char FIRE_MODEL_PATH[] = { "Data/Model/trap/fire.mv1" };
static const int FIRE_NUM = 10;
class CFireManager :public CTrapManagerBase {
private:

	CFire m_fire[FIRE_NUM];

public:
	CFireManager();

	~CFireManager();

	void Init();

	void Load();

	void Step(VECTOR pos);

	void Draw();

	void DrawA();

	void Exit();

	void Update();

	void Request(VECTOR pos, bool hit);

	void Reset();

	CFire& GetFire(int i) { return m_fire[i]; }
};