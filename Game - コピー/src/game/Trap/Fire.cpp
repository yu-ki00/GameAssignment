#include"Fire.h"
#include"../system/effectData/effectData.h"
#include "../../lib/effekseer/effekseer.h"

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
	if (!m_isActive)return;
	if (m_coolTime <= 0) {
		m_isFire = true;
	}
	else {
		m_coolTime--;
	}
	if (m_isFire) {

	}
}
void CFire::Request(VECTOR pos) {
	CTrapBase::Request(pos);
	int effectId = CEffectData::GetId(EFFECT_GATE);
	CEffekseerCtrl::Request(effectId, m_pos, false);
}