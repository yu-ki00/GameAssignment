#include"Fire.h"

CFire::CFire() {
	Init();
}

CFire::~CFire() {
	Exit();
}

void CFire::Init() {
	CTrapBase::Init();
	m_coolTime = 0;
	m_isFire = true;
}
void CFire::Step(VECTOR pos) {
	CTrapBase::Step(pos);
	if (m_coolTime <= 0) {
		m_isFire = true;
	}
	else {
		m_coolTime--;
	}
	if (m_isFire) {

	}
}