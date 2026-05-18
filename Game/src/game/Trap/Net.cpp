#include"Net.h"

CNet::CNet() {
	Init();
}

CNet::~CNet() {
	Exit();
}

void CNet::Init() {
	CObject3D::Init();
	m_isActive = false;
}

void CNet::Load(int originHndl) {
	if (m_hndl == -1) {
		m_hndl = MV1DuplicateModel(originHndl);
		MV1SetupCollInfo(m_hndl);
	}

}

void CNet::Step() {

}

void CNet::Draw() {
	if (m_isActive) {
		MV1DrawModel(m_hndl);
	}
}

void CNet::Update() {
	CObject3D::Update();
	MV1RefreshCollInfo(m_hndl);
}

void CNet::Exit() {
	if (m_hndl != -1) {
		MV1DeleteModel(m_hndl);

		m_hndl = -1;
	}
}

void CNet::Request(VECTOR pos) {
	m_isActive = true;

	m_pos = pos;


}