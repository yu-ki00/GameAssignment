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

void CEnemyManager::Request(VECTOR pos, bool hit) {
	if (hit) {
		for (int i = 0; i < ENEMY_NUM; i++) {
			if (!m_enemy[i].GetActive()) {
				m_enemy[i].SetActive(true);
				m_enemy[i].SetPos(pos);
				break;
			}
		}
	}
}