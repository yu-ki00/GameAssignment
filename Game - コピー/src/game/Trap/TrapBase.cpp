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
		MV1DuplicateModel(originHndl);
	}

	MV1SetupCollInfo(m_hndl);	// ƒRƒŠƒWƒ‡ƒ“î•ñ\’z
}

void CTrapBase::Step() {

}

void CTrapBase::Draw() {
	if (m_isActive) {
		MV1DrawModel(m_hndl);
	}
}

void CTrapBase::Exit() {
	if (m_hndl != -1) {
		MV1DeleteModel(m_hndl);

		m_hndl = -1;
	}
}