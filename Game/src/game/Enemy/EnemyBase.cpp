#include"EnemyBase.h"

CEnemyBase::CEnemyBase() {
	Init();
}

CEnemyBase::~CEnemyBase() {
	Exit();
}

void CEnemyBase::Init() {
	CObject3D::Init();
	m_isActive = false;
}

void CEnemyBase::Load(int originHndl) {
	if (m_hndl == -1) {
		MV1DuplicateModel(originHndl);
	}

	MV1SetupCollInfo(m_hndl);	// ƒRƒŠƒWƒ‡ƒ“î•ñ\’z
}

void CEnemyBase::Step() {

}

void CEnemyBase::Draw() {
	if (m_isActive) {
		MV1DrawModel(m_hndl);
	}
}

void CEnemyBase::Exit() {
	if (m_hndl != -1) {
		MV1DeleteModel(m_hndl);

		m_hndl = -1;
	}
}