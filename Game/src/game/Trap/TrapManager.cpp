#include"TrapManager.h"


CTrapManager::CTrapManager() {
	for (int i = 0; i < TrapNum; i++) {
		m_trap[i] = nullptr;
	}
	m_trap[0] = new CSpikeManager;
	m_trap[1] = new CNetManager;
}

CTrapManager::~CTrapManager() {
	for (int i = 0; i < TrapNum; i++)
	{
		delete m_trap[i];
	}
}

void CTrapManager::Init() {
	for (int i = 0;i < TrapNum;i++) {
		m_trap[i]->Init();
	}
}

void CTrapManager::Load() {
	for (int i = 0;i < TrapNum;i++) {
		m_trap[i]->Load();
	}
}

void CTrapManager::Draw() {
	for (int i = 0;i < TrapNum;i++) {
		m_trap[i]->Draw();
	}
}

void CTrapManager::Step() {
	for (int i = 0;i < TrapNum;i++) {
		m_trap[i]->Step();
	}
}

void CTrapManager::Update() {
	for (int i = 0;i < TrapNum;i++) {
		m_trap[i]->Update();
	}
}

void CTrapManager::Exit() {
	for (int i = 0;i < TrapNum;i++) {
		m_trap[i]->Exit();
	}
}

void CTrapManager::Request(VECTOR pos, bool hit, TrapType type)
{
	switch (type)
	{
	case Spike:
		m_trap[Spike]->Request(pos, hit);
		break;
	case Net:
		m_trap[Net]->Request(pos, hit);
		break;
	case TrapNum:
		break;
	default:
		break;
	}
}

CSpike& CTrapManager::GetSpike(int i)
{
	CSpikeManager* spikeMgr =dynamic_cast<CSpikeManager*>(m_trap[Spike]);

	return spikeMgr->GetSpike(i);
}

CNet& CTrapManager::GetNet(int i)
{
	CNetManager* netManager = dynamic_cast<CNetManager*>(m_trap[Net]);

	return netManager->GetNet(i);
}