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
	m_waitTime = 0;
}

void CEnemyManager::Load() {

	int hndl = MV1LoadModel(ENEMY_MODEL_PATH);

	for (int i = 0; i < ENEMY_NUM; i++) {

		m_enemy[i].Load(hndl);
	}
	MV1DeleteModel(hndl);
}

void CEnemyManager::Step(VECTOR startpos, VECTOR endpos) {

	m_waitTime++;
	for (int i = 0; i < ENEMY_NUM; i++) {

		if (m_waitTime >= WAIT_TIME && !m_enemy[i].GetActive()) {
			m_waitTime = 0;

			m_enemy[i].Request(startpos);
			break;
		}
	}
	for (int i = 0; i < ENEMY_NUM; i++) {

		m_enemy[i].Step(endpos);

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
