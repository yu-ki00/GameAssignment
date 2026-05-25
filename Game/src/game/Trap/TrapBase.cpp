#include"TrapBase.h"

CTrapBase::CTrapBase() {
	Init();
}

CTrapBase::~CTrapBase() {
	Exit();
}

void CTrapBase::Init() {
	CObject3D::Init();
	m_isActive = false;
}

void CTrapBase::Load(int originHndl) {
	if (m_hndl == -1) {
		m_hndl = MV1DuplicateModel(originHndl);
		MV1SetupCollInfo(m_hndl);
	}

}

void CTrapBase::Step(VECTOR pos) {
	if (!m_isActive) {
		m_pos = pos;
	}
}

void CTrapBase::Draw() {
	if (m_isActive) {
		COLOR_F color = { 1.0f, 1.0f, 1.0f, 1.0f };
		MV1SetDifColorScale(m_hndl, color);
		MV1DrawModel(m_hndl);
	}
}

void CTrapBase::DrawA() {
	if (!m_isActive) {
		COLOR_F color = { 1.0f, 1.0f, 1.0f, 0.05f };
		MV1SetDifColorScale(m_hndl, color);
		MV1DrawModel(m_hndl);
	}
}

void CTrapBase::Update() {
	CObject3D::Update();
	MV1RefreshCollInfo(m_hndl);
}

void CTrapBase::Exit() {
	if (m_hndl != -1) {
		MV1DeleteModel(m_hndl);

		m_hndl = -1;
	}
}

void CTrapBase::Request(VECTOR pos) {
	m_isActive = true;

	m_pos = pos;


}

void CTrapBase::Reset() {
	m_isActive = false;
}