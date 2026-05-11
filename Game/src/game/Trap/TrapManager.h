#pragma once
#include"TrapBase.h"
#include"Spike.h"

static const char SPIKE_MODEL_PATH[] = { "Data/Model/trap/spike.mv1" };
static const int SPIKE_NUM = 10;
class CTrapManager {
private:

	CSpike m_spike[SPIKE_NUM];

public:
	CTrapManager();
	
	~CTrapManager();

	void Init();

	void Load();

	void Step();

	void Draw();

	void Exit();

	void Update();

	void Request(VECTOR pos, bool hit);

	CSpike& GetSpike(int i) { return m_spike[i]; }
};