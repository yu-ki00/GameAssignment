#include"crystal.h"

CCrystal::CCrystal() {
	Init();
}

CCrystal::~CCrystal() {
	Exit();
}

void CCrystal::Init() {

	CObject3D::Init();
}

void CCrystal::Load(VECTOR pos) {

	if (m_hndl == -1) {
		m_hndl = MV1LoadModel(CRYSTAL_PATH);
	}
	m_pos = pos;
}

void CCrystal::Step() {
	m_rot.y += 0.01f;
	if (m_rot.y >= DX_PI_F * 2) {
		m_rot.y = 0;
	}

	if (m_hp <= 0)
	{
		m_isActive = false;

	}
}
