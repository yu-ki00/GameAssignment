#include"TrapManager.h"


CTrapManager::CTrapManager() {
	for (int i = 0; i < TrapNum; i++) {
		m_trap[i] = nullptr;
	}
	m_trap[0] = new CNetManager;
	m_trap[1] = new CSpikeManager;
	m_trap[2] = new CFireManager;
}

CTrapManager::~CTrapManager() {
	for (int i = 0; i < TrapNum; i++)
	{
		delete m_trap[i];
	}
}

void CTrapManager::Init() {
	for (int i = 0; i < TrapNum; i++) {
		m_trap[i]->Init();
	}
}

void CTrapManager::Load() {
	for (int i = 0; i < TrapNum; i++) {
		m_trap[i]->Load();
	}
}

void CTrapManager::Draw() {
	for (int i = 0; i < TrapNum; i++) {
		m_trap[i]->Draw();
	}
}
void CTrapManager::DrawA(TrapType type) {
	switch (type)
	{
	case Net:
		m_trap[Net]->DrawA();
		break;
	case Spike:
		m_trap[Spike]->DrawA();
		break;
	case Fire:
		m_trap[Fire]->DrawA();
		break;
	}
}

void CTrapManager::Step(VECTOR pos) {
	for (int i = 0; i < TrapNum; i++) {
		m_trap[i]->Step(pos);
	}
}

void CTrapManager::Update() {
	for (int i = 0; i < TrapNum; i++) {
		m_trap[i]->Update();
	}
}

void CTrapManager::Exit() {
	for (int i = 0; i < TrapNum; i++) {
		m_trap[i]->Exit();
	}
}

void CTrapManager::Request(VECTOR pos, bool hit, TrapType type)
{
	switch (type)
	{
	case Net:
		m_trap[Net]->Request(pos, hit);
		break;
	case Spike:
		m_trap[Spike]->Request(pos, hit);
		break;
	case Fire:
		m_trap[Fire]->Request(pos, hit);
		break;
	case TrapNum:
		break;
	default:
		break;
	}
}

CSpike& CTrapManager::GetSpike(int i)
{
	CSpikeManager* spikeMgr = dynamic_cast<CSpikeManager*>(m_trap[Spike]);

	return spikeMgr->GetSpike(i);
}

CNet& CTrapManager::GetNet(int i)
{
	CNetManager* netManager = dynamic_cast<CNetManager*>(m_trap[Net]);

	return netManager->GetNet(i);
}
CFire& CTrapManager::GetFire(int i)
{
	CFireManager* fireManager = dynamic_cast<CFireManager*>(m_trap[Fire]);

	return fireManager->GetFire(i);
}

void CTrapManager::Reset() {
	for (int i = 0; i < TrapNum; i++) {
		m_trap[i]->Reset();
	}
}