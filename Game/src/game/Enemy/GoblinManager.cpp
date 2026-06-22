#include"GoblinManager.h"
#include"../collision/collisionManager.h"

CGoblinManager::CGoblinManager() {

	Init();


}

CGoblinManager::~CGoblinManager() {

}

void CGoblinManager::Init() {
	for (int i = 0; i < GOBLIN_NUM; i++) {

		m_goblin[i].Init();

	}
	m_waitTime = WAIT_TIME;
	m_waveEnemy = 2;
}

void CGoblinManager::Load() {

	int hndl = MV1LoadModel(GOBLIN_MODEL_PATH);

	for (int i = 0; i < GOBLIN_NUM; i++) {

		m_goblin[i].Load(hndl);
	}
	MV1DeleteModel(hndl);
}

void CGoblinManager::Step() {


	for (int i = 0; i < GOBLIN_NUM; i++) {

		m_goblin[i].Step();

	}
}

void CGoblinManager::Draw() {

	for (int i = 0; i < GOBLIN_NUM; i++) {
		m_goblin[i].Draw();

	}
}

void CGoblinManager::Update() {
	for (int i = 0; i < GOBLIN_NUM; i++) {
		m_goblin[i].Update();

	}
}

void CGoblinManager::Exit() {
	for (int i = 0; i < GOBLIN_NUM; i++) {
		m_goblin[i].Exit();

	}
}

void CGoblinManager::Request(VECTOR startpos,const vector<VECTOR>&path) {
	m_waitTime++;

	int pop = 0;

	for (int i = 0; i < GOBLIN_NUM; i++) {

		if (m_waitTime >= WAIT_TIME && !m_goblin[i].GetActive() && !m_goblin[i].GetIsDeath()) {

			int ranx = GetRand(200) - 100;

			int ranz = GetRand(200) - 100;

			VECTOR aa = VAdd(startpos, VGet((float)ranx, 0.0f, (float)ranz));

			m_goblin[i].Request(aa);

			m_goblin[i].SetPath(path);
			pop++;
			if (pop == m_waveEnemy) {
				m_waitTime = 0;
				m_waveEnemy++;
				break;
			}

		}
	}
}

bool CGoblinManager::IsAllDead() {
	for (int i = 0;i < GOBLIN_NUM;i++) {
		if (!m_goblin[i].GetIsDeath()) {
			return false;
		}
	}
	return true;
}

void CGoblinManager::Reset() {
	for (int i = 0;i < GOBLIN_NUM;i++) {
		m_goblin[i].Reset();
	}
	m_waitTime = WAIT_TIME;
	m_waveEnemy = 2;
}
CEnemyBase* CGoblinManager::GetEnemy(int i) {
	return &m_goblin[i];
}