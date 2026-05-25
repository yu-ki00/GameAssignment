#pragma once
#include"TrapManagerbase.h"
#include"SpikeManager.h"
#include"NetManager.h"
#include"FireManager.h"
enum TrapType {
	Spike,
	Net,
	Fire,

	TrapNum
};
class CTrapManager {
private:

	bool m_TrapData;

	CTrapManagerBase* m_trap[TrapNum];
public:
	CTrapManager();

	~CTrapManager();

	void Init();

	void Load();

	void Step(VECTOR pos);

	void Draw();

	void DrawA(TrapType type);

	void Exit();

	void Update();

	void Request(VECTOR pos, bool hit,TrapType type);

	CSpike& GetSpike(int i);

	CNet& GetNet(int i);

	CFire& GetFire(int i);

	void Reset();
};