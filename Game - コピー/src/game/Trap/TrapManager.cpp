#include"TrapManager.h"
#include"SpikeManager.h"
#include"NetManager.h"

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

void CTrapManager::Request(VECTOR pos, bool hit,TrapType type)
{
	for (int i = 0;i < TrapNum;i++) {
		m_trap[i]->Request(pos,hit);
	}
}