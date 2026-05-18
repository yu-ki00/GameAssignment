#pragma once
#include"TrapManagerbase.h"
enum TrapType {
	Spike,
	Net,

	TrapNum
};
class CTrapManager {
private:

	CTrapManagerBase* m_trap[TrapNum];
public:
	CTrapManager();

	~CTrapManager();

	void Init();

	void Load();

	void Step();

	void Draw();

	void Exit();

	void Update();

	void Request(VECTOR pos, bool hit,TrapType type);
};