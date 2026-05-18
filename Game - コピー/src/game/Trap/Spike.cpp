#include"Spike.h"

CSpike::CSpike() {
	Init();
}

CSpike::~CSpike() {
	Exit();
}

void CSpike::Init() {
	CObject3D::Init();
	m_isActive = false;
}

void CSpike::Load(int originHndl) {
	if (m_hndl == -1) {
		m_hndl=MV1DuplicateModel(originHndl);
		MV1SetupCollInfo(m_hndl);
	}

}

void CSpike::Step() {

}

void CSpike::Draw() {
	if (m_isActive) {
		MV1DrawModel(m_hndl);
	}
}

void CSpike::Update() {
	CObject3D::Update();
	MV1RefreshCollInfo(m_hndl);
}

void CSpike::Exit(){
	if (m_hndl != -1) {
		MV1DeleteModel(m_hndl);
		
		m_hndl = -1;
	}
}

void CSpike::Request(VECTOR pos) {
	m_isActive = true;

	m_pos = pos;


}