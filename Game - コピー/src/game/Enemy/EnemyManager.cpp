#include"EnemyManager.h"
#include"../collision/collisionManager.h"

CEnemyManager::CEnemyManager() {

	Init();


}

CEnemyManager::~CEnemyManager() {

}

void CEnemyManager::Init() {
	for (int i = 0; i < ENEMY_NUM; i++) {

		m_enemy[i].Init();

	}
	m_waitTime = WAIT_TIME;
	m_waveEnemy = 2;
}

void CEnemyManager::Load() {

	int hndl = MV1LoadModel(ENEMY_MODEL_PATH);

	for (int i = 0; i < ENEMY_NUM; i++) {

		m_enemy[i].Load(hndl);
	}
	MV1DeleteModel(hndl);
}

void CEnemyManager::Step() {


	for (int i = 0; i < ENEMY_NUM; i++) {

		m_enemy[i].Step();

	}
}

void CEnemyManager::Draw() {

	for (int i = 0; i < ENEMY_NUM; i++) {
		m_enemy[i].Draw();

	}
}

void CEnemyManager::Update() {
	for (int i = 0; i < ENEMY_NUM; i++) {
		m_enemy[i].Update();

	}
}

void CEnemyManager::Exit() {
	for (int i = 0; i < ENEMY_NUM; i++) {
		m_enemy[i].Exit();

	}
}

void CEnemyManager::Request(VECTOR startpos,const vector<VECTOR>&path) {
	m_waitTime++;

	int pop = 0;

	for (int i = 0; i < ENEMY_NUM; i++) {

		if (m_waitTime >= WAIT_TIME && !m_enemy[i].GetActive() && !m_enemy[i].GetIsDeath()) {

			int ranx = GetRand(200) - 100;

			int ranz = GetRand(200) - 100;

			VECTOR aa = VAdd(startpos, VGet((float)ranx, 0.0f, (float)ranz));

			m_enemy[i].Request(aa);

			m_enemy[i].SetPath(path);
			pop++;
			if (pop == m_waveEnemy) {
				m_waitTime = 0;
				m_waveEnemy++;
				break;
			}

		}
	}
}

bool CEnemyManager::IsAllDead() {
	for (int i = 0;i < ENEMY_NUM;i++) {
		if (!m_enemy[i].GetIsDeath()) {
			return false;
		}
	}
	return true;
}

void CEnemyManager::Reset() {
	for (int i = 0;i < ENEMY_NUM;i++) {
		m_enemy[i].Reset();
	}
	m_waitTime = WAIT_TIME;
	m_waveEnemy = 2;
}