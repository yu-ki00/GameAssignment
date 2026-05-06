#include"TrapManager.h"
#include"../collision/collisionManager.h"

CTrapManager::CTrapManager() {

	Init();


}

CTrapManager::~CTrapManager() {

}

void CTrapManager::Init() {
	for (int i = 0; i < SPIKE_NUM; i++) {
		m_spike[i].Init();

	}
}

void CTrapManager::Load() {
	int hndl = MV1LoadModel(SPIKE_MODEL_PATH);
	for (int i = 0; i < SPIKE_NUM; i++) {
		m_spike[i].Load(hndl);

	}
	MV1DeleteModel(hndl);
}

void CTrapManager::Step() {
	for (int i = 0; i < SPIKE_NUM; i++) {
		m_spike[i].Step();

	}
}

void CTrapManager::Draw() {
	for (int i = 0; i < SPIKE_NUM; i++) {
		m_spike[i].Draw();

	}
}

void CTrapManager::Update() {
	for (int i = 0; i < SPIKE_NUM; i++) {
		m_spike[i].Update();

	}
}

void CTrapManager::Exit() {
	for (int i = 0; i < SPIKE_NUM; i++) {
		m_spike[i].Exit();

	}
}

void CTrapManager::Request(VECTOR pos,bool hit) {
	if (hit) {
		for (int i = 0; i < SPIKE_NUM; i++) {
			if (!m_spike[i].GetActive()) {
				m_spike[i].SetActive(true);
				m_spike[i].SetPos(pos);
				break;
			}
		}
	}
}