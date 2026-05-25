#include"Enemy.h"
#include"math.h"
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
	m_isFire = false;
	m_isDamage = false;
	m_isDeath = false;
}

void CEnemy::Load(int originHndl) {
	if (m_hndl == -1) {
		m_hndl = MV1DuplicateModel(originHndl);
	}

	MV1SetupCollInfo(m_hndl);	// ƒRƒŠƒWƒ‡ƒ“î•ñ\’z
}

void CEnemy::Step(VECTOR endpos) {
	float speed = ENEMY_SPEED;
	if (m_slow) {
		speed /= 2;
	}
	if (m_isActive) {
		VECTOR diff = VSub(endpos, m_pos);

		VECTOR norm = VNorm(diff);
		if (VSize(diff) >= 100) {
			VECTOR SPEED = VScale(norm, speed);
			m_pos = VAdd(m_pos, SPEED);
		}
		m_rot.y = atan2f(-norm.x, -norm.z);
		if (m_hp <= 0) {
			m_isActive = false;
			m_isDeath = true;
		}
	}
	if (m_isKnock) {
		m_knockTime--;
		m_pos = VAdd(m_pos, m_knockPow);
		if (m_knockTime <= 0) {
			m_isKnock = false;
		}
	}
	if (m_isDamage) {
		m_damageTime--;
		if (m_damageTime <= 0)
		{
			m_isDamage = false;
		}
	}
	if (m_isFire) {
		m_fireTime--;
			m_hp -= 0.2f;
		if (m_fireTime <= 0) {
			m_isFire = false;;
		}
	}

}

void CEnemy::Draw() {
	if (m_isActive) {
		if (m_isDamage) {
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
	m_isDamage = true;
	m_damageTime = 4;

}

void CEnemy::SetFire() {
	m_isFire = true;
	m_fireTime = 180;
	m_hp -= 0.2;
}

void CEnemy::KnockBack(VECTOR vec) {
	m_knockPow = VScale(vec, 15);
	m_knockTime = 30;
	m_isKnock = true;
}

void CEnemy::Reset() {
	m_hp = ENEMY_HP;
	m_isActive = false;
	m_isKnock = false;
	m_isFire = false;
	m_isDamage = false;
	m_isDeath = false;
}