#include"HGoblinManager.h"
#include"../collision/collisionManager.h"

CHGManager::CHGManager() {

	Init();


}

CHGManager::~CHGManager() {

}

void CHGManager::Init() {
	for (int i = 0; i < HG_NUM; i++) {

		m_hg[i].Init();

	}
	m_waitTime = WAIT_TIME2;
	m_waveEnemy = 2;
}

void CHGManager::Load() {

	int hndl = MV1LoadModel(HG_MODEL_PATH);

	for (int i = 0; i < HG_NUM; i++) {

		m_hg[i].Load(hndl);
	}
	MV1DeleteModel(hndl);
}

void CHGManager::Step() {


	for (int i = 0; i < HG_NUM; i++) {

		m_hg[i].Step();

	}
}

void CHGManager::Draw() {

	for (int i = 0; i < HG_NUM; i++) {
		m_hg[i].Draw();

	}
}

void CHGManager::Update() {
	for (int i = 0; i < HG_NUM; i++) {
		m_hg[i].Update();

	}
}

void CHGManager::Exit() {
	for (int i = 0; i < HG_NUM; i++) {
		m_hg[i].Exit();

	}
}

void CHGManager::Request(VECTOR startpos, const vector<VECTOR>& path) {
	m_waitTime++;

	int pop = 0;

	for (int i = 0; i < HG_NUM; i++) {

		if (m_waitTime >= WAIT_TIME && !m_hg[i].GetActive() && !m_hg[i].GetIsDeath()) {

			int ranx = GetRand(200) - 100;

			int ranz = GetRand(200) - 100;

			VECTOR aa = VAdd(startpos, VGet((float)ranx, 0.0f, (float)ranz));

			m_hg[i].Request(aa);

			m_hg[i].SetPath(path);
			pop++;
			if (pop == m_waveEnemy) {
				m_waitTime = 0;
				m_waveEnemy++;
				break;
			}

		}
	}
}

bool CHGManager::IsAllDead() {
	for (int i = 0;i < HG_NUM;i++) {
		if (!m_hg[i].GetIsDeath()) {
			return false;
		}
	}
	return true;
}

void CHGManager::Reset() {
	for (int i = 0;i < HG_NUM;i++) {
		m_hg[i].Reset();
	}
	m_waitTime = WAIT_TIME2;
	m_waveEnemy = 2;
}