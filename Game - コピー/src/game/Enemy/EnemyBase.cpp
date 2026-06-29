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

	MV1SetupCollInfo(m_hndl);	// ÉRÉäÉWÉáÉìèÓïÒç\íz
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

void CEnemyBase::HitDamage()
{
	m_isDamage = true;

	m_damageTime = 4;

}

void CEnemyBase::SetFire() {
	m_isFire = true;
	m_fireTime = 180;
	m_hp -= 0.2f;
}

void CEnemyBase::KnockBack(VECTOR vec) {
	m_knockPow = VScale(vec, 3);
	m_knockTime = 30;
	m_isKnock = true;
}

void CEnemyBase::SetPath(const vector<VECTOR>& path) {
	m_path = path;
	m_pathIndex = 0;
}
