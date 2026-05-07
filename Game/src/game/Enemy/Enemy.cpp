#include"Enemy.h"

CEnemy::CEnemy() {
	Init();
}

CEnemy::~CEnemy() {
	Exit();
}

void CEnemy::Init() {
	CObject3D::Init();
	m_isActive = false;
}

void CEnemy::Load(int originHndl) {
	if (m_hndl == -1) {
		m_hndl = MV1DuplicateModel(originHndl);
	}

	MV1SetupCollInfo(m_hndl);	// ƒRƒŠƒWƒ‡ƒ“î•ñ\’z
}

void CEnemy::Step() {

}

void CEnemy::Draw() {
	if (m_isActive) {
		MV1DrawModel(m_hndl);
	}
}

void CEnemy::Exit() {
	if (m_hndl != -1) {
		MV1DeleteModel(m_hndl);

		m_hndl = -1;

	}
}