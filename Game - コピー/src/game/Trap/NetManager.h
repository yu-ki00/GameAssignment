#pragma once
#include"TrapBase.h"
#include"Net.h"
#include"TrapManagerbase.h"

static const char NET_MODEL_PATH[] = { "Data/Model/trap/net.mv1" };
static const int NET_NUM = 10;
class CNetManager:public CTrapManagerBase {
private:

	CNet m_net[NET_NUM];

public:
	CNetManager();

	~CNetManager();

	void Init();

	void Load();

	void Step();

	void Draw();

	void Exit();

	void Update();

	void Request(VECTOR pos, bool hit);

	CNet& GetNet(int i) { return m_net[i]; }
};