#include"Enemy.h"

CEnemy::CEnemy() {
	Init();
}

CEnemy::~CEnemy() {
	Exit();
}

void CEnemy::Init() {
	CObject3D::Init();
	m_hp = ENEMY_HP;
	m_isActive = false;
	m_isKnock = false;
	
}

void CEnemy::Load(int originHndl) {
	if (m_hndl == -1) {
		m_hndl = MV1DuplicateModel(originHndl);
	}

	MV1SetupCollInfo(m_hndl);	// ÉRÉäÉWÉáÉìèÓïÒç\íz
}

void CEnemy::Step(VECTOR endpos) {
	float speed = ENEMY_SPEED;
	if (m_slow) {
		speed /= 2;
	}
	if (m_isActive) {
		VECTOR SPEED = VScale(VNorm(VSub(endpos, m_pos)), speed);
		m_pos = VAdd(m_pos, SPEED);
		if (m_hp <= 0) {
			m_isActive = false;
		}
	}
	if (m_isKnock) {
		m_knockTime--;
		m_pos = VAdd(m_pos, m_knockPow);
		if (m_knockTime<=0) {
			m_isKnock = false;
		}
	}
	switch (m_state)
	{
	case CEnemy::NORMAL:
		break;
	case CEnemy::FIRE:
		m_fireTime--;
		if (m_fireTime % 60 == 0) {
			m_hp -= 2;
		}
		if (m_fireTime <= 0) {
			m_state = NORMAL;
		}
		break;
	case CEnemy::DAMAGE:
		m_damageTime--;
		if (m_damageTime <= 0)
		{
			m_state = NORMAL;
		}
		break;
	default:
		break;
	}
}

void CEnemy::Draw() {
	if (m_isActive) {
		if (m_state == DAMAGE) {
			COLOR_F color = { 1.0f, 0.3f, 0.3f, 0.3f };
			MV1SetDifColorScale(m_hndl, color);
		}
		else {
			COLOR_F color = { 1.0f, 1.0f, 1.0f, 1.0f };
			MV1SetDifColorScale(m_hndl, color);
		}
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

	m_pos = pos;

	m_hp = ENEMY_HP;

}

VECTOR CEnemy::GetCenter() {
	VECTOR center = m_pos;
	center.y += ENEMY_RADIUS;
	return center;

}

void CEnemy::HitDamage() 
{ 
	m_state = DAMAGE;
	m_damageTime = 2;

}

void CEnemy::IsFire() {
	m_state = FIRE;
	m_fireTime = 180;
}

void CEnemy::KnockBack(VECTOR vec) {
	m_knockPow = VScale(vec, 15);
	m_knockTime = 30;
	m_isKnock = true;
}