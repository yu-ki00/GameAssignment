#include"EnemyManager.h"

CEnemyManager::CEnemyManager() {
	for (int i = 0;i < EnemyNum;i++) {
		m_enemy[i] = nullptr;
	}
	m_enemy[0] = new CGoblinManager;
	m_enemy[1] = new CHGManager;
}

CEnemyManager::~CEnemyManager() {
	for (int i = 0;i < EnemyNum;i++) {
		delete m_enemy[i];
	}
}

void CEnemyManager::Init() {
	for (int i = 0;i < EnemyNum;i++) {
		m_enemy[i]->Init();
	}
}

void CEnemyManager::Load() {
	for (int i = 0;i < EnemyNum;i++) {
		m_enemy[i]->Load();
	}
}

void CEnemyManager::Step() {
	for (int i = 0;i < EnemyNum;i++) {
		m_enemy[i]->Step();
	}
}

void CEnemyManager::Draw() {
	for (int i = 0;i < EnemyNum;i++) {
		m_enemy[i]->Draw();
	}
}

void CEnemyManager::Exit() {
	for (int i = 0;i < EnemyNum;i++) {
		m_enemy[i]->Exit();
	}
}

void CEnemyManager::Update() {
	for (int i = 0;i < EnemyNum;i++) {
		m_enemy[i]->Update();
	}
}

void CEnemyManager::Request(VECTOR startpos, const vector<VECTOR>& path,EnemyType enemy) {
	switch (enemy)
	{
	case Gob:
		m_enemy[Gob]->Request(startpos, path);
		break;
	case HGob:
		m_enemy[HGob]->Request(startpos, path);
		break;
	default:
		break;
	}
}

CGoblin& CEnemyManager::GetGoblin(int i) {
	CGoblinManager* goblinMgr = dynamic_cast<CGoblinManager*>(m_enemy[Gob]);
	return goblinMgr->GetGoblin(i);
}

CHGoblin& CEnemyManager::GetHGoblin(int i) {
	CHGManager* HGMgr = dynamic_cast<CHGManager*>(m_enemy[HGob]);
	return HGMgr->GetHGoblin(i);
}

void CEnemyManager::Reset() {
	for (int i = 0;i < EnemyNum;i++) {
		m_enemy[i]->Reset();
	}
}
bool CEnemyManager::IsAllDead() {
	bool ret = true;
	for (int i = 0;i < EnemyNum;i++) {
		ret=m_enemy[i]->IsAllDead();
		if (!ret) {
			return ret;
		}

	}
	return ret;
}