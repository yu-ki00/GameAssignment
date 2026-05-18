#include"NetManager.h"
#include"../collision/collisionManager.h"
using namespace std;


CNetManager::CNetManager() {

	Init();

}

CNetManager::~CNetManager() {

}

void CNetManager::Init() {


	for (int i = 0; i < NET_NUM; i++) {
		m_net[i].Init();

	}
}

void CNetManager::Load() {
	int hndl = MV1LoadModel(NET_MODEL_PATH);
	for (int i = 0; i < SPIKE_NUM; i++) {
		m_net[i].Load(hndl);

	}
	MV1DeleteModel(hndl);
}

void CNetManager::Step() {
	for (int i = 0; i < NET_NUM; i++) {
		m_net[i].Step();

	}
}

void CNetManager::Draw() {
	for (int i = 0; i < NET_NUM; i++) {
		m_net[i].Draw();

	}
}

void CNetManager::Update() {
	for (int i = 0; i < NET_NUM; i++) {
		m_net[i].Update();

	}
}

void CNetManager::Exit() {
	for (int i = 0; i < SPIKE_NUM; i++) {
		m_net[i].Exit();

	}
}

void CNetManager::Request(VECTOR pos, bool hit) {
	if (hit) {
		for (int i = 0; i < NET_NUM; i++) {
			if (!m_net[i].GetActive()) {
				m_net[i].Request(pos);
				break;
			}
		}
	}
}