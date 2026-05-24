#include"FireManager.h"
#include"../collision/collisionManager.h"
using namespace std;


CFireManager::CFireManager() {

	Init();

}

CFireManager::~CFireManager() {

}

void CFireManager::Init() {


	for (int i = 0; i < FIRE_NUM; i++) {
		m_fire[i].Init();

	}
}

void CFireManager::Load() {
	int hndl = MV1LoadModel(FIRE_MODEL_PATH);
	for (int i = 0; i < FIRE_NUM; i++) {
		m_fire[i].Load(hndl);

	}
	MV1DeleteModel(hndl);
}

void CFireManager::Step() {
	for (int i = 0; i < FIRE_NUM; i++) {
		m_fire[i].Step();

	}
}

void CFireManager::Draw() {
	for (int i = 0; i < FIRE_NUM; i++) {
		m_fire[i].Draw();

	}
}

void CFireManager::Update() {
	for (int i = 0; i < FIRE_NUM; i++) {
		m_fire[i].Update();

	}
}

void CFireManager::Exit() {
	for (int i = 0; i < FIRE_NUM; i++) {
		m_fire[i].Exit();

	}
}

void CFireManager::Request(VECTOR pos, bool hit) {
	if (hit) {
		for (int i = 0; i < FIRE_NUM; i++) {
			if (!m_fire[i].GetActive()) {
				m_fire[i].Request(pos);
				break;
			}
		}
	}
}