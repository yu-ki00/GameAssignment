#include"Enemy.h"

CEnemy::CEnemy() {
	Init();
}

CEnemy::~CEnemy() {
	Exit();
}

void CEnemy::Init() {
	CObject3D::Init();
	m_hp = 200;
	m_isActive = false;
}

void CEnemy::Load(int originHndl) {
	if (m_hndl == -1) {
		m_hndl = MV1DuplicateModel(originHndl);
	}

	MV1SetupCollInfo(m_hndl);	// ƒRƒŠƒWƒ‡ƒ“î•ñ\’z
}

void CEnemy::Step(VECTOR endpos) {
	if (m_isActive) {
		VECTOR SPEED = VScale(VNorm(VSub(endpos,m_pos)), 3);
		m_pos = VAdd(m_pos, SPEED);
		if (m_hp <= 0) {
			m_isActive = false;
		}
	}
}

void CEnemy::Draw() {
	if (m_isActive) {
		MV1DrawModel(m_hndl);
		DrawSphere3D(GetCenter(), ENEMY_RADIUS, 8, RED, RED, true);
	}
}

void CEnemy::Exit() {
	if (m_hndl != -1) {
		MV1DeleteModel(m_hndl);

		m_hndl = -1;

	}
}

void CEnemy::Request(VECTOR pos) {

	m_isActive = true;

	m_pos=pos;

}

VECTOR CEnemy::GetCenter() {
	VECTOR center=m_pos;
	center.y += ENEMY_RADIUS;
	return center;

}