#pragma once
#include"TrapBase.h"
#include"Spike.h"
class CTrapManager {
private:

	CSpike m_spike;

public:
	CTrapManager();
	
	~CTrapManager();

	void Init();

	void Load();

	void Step();

	void Draw();

	void Exit();
};