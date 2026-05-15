#include"TrapManager.h"
#include"../collision/collisionManager.h"
using namespace std;


CSpikeManager::CSpikeManager() {

	Init();

}

CSpikeManager::~CSpikeManager() {

}

void CSpikeManager::Init() {


	for (int i = 0; i < SPIKE_NUM; i++) {
		m_spike[i].Init();

	}
}

void CSpikeManager::Load() {
	int hndl = MV1LoadModel(SPIKE_MODEL_PATH);
	for (int i = 0; i < SPIKE_NUM; i++) {
		m_spike[i].Load(hndl);

	}
	MV1DeleteModel(hndl);
}

void CSpikeManager::Step() {
	for (int i = 0; i < SPIKE_NUM; i++) {
		m_spike[i].Step();

	}
}

void CSpikeManager::Draw() {
	for (int i = 0; i < SPIKE_NUM; i++) {
		m_spike[i].Draw();

	}
}

void CSpikeManager::Update() {
	for (int i = 0; i < SPIKE_NUM; i++) {
		m_spike[i].Update();

	}
}

void CSpikeManager::Exit() {
	for (int i = 0; i < SPIKE_NUM; i++) {
		m_spike[i].Exit();

	}
}

void CSpikeManager::Request(VECTOR pos,bool hit) {
	if (hit) {
		for (int i = 0; i < SPIKE_NUM; i++) {
			if (!m_spike[i].GetActive()) {
				m_spike[i].Request(pos);
				break;
			}
		}
	}
}