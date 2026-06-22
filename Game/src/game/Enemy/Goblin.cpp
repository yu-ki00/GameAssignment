#include"Goblin.h"
#include"math.h"
CGoblin::CGoblin() {
	Init();
}

CGoblin::~CGoblin() {
	Exit();
}

void CGoblin::Init() {
	CObject3D::Init();
	m_hp = GOBLIN_HP;
	m_isActive = false;
	m_isKnock = false;
	m_isFire = false;
	m_isDamage = false;
	m_isDeath = false;
}

void CGoblin::Load(int originHndl) {

	if (m_hndl == -1) {

		m_hndl = MV1DuplicateModel(originHndl);

	}

	MV1SetupCollInfo(m_hndl);	// ƒRƒŠƒWƒ‡ƒ“î•ñ\’z
}

void CGoblin::Step() {
	float speed = GOBLIN_SPEED;
	if (m_slow) {
		speed /= 2;
	}
	if (m_isActive)
	{
		if (m_pathIndex >= m_path.size())
		{

			return;
		}

		float speed = GOBLIN_SPEED;

		if (m_slow)
		{
			speed /= 2;
		}

		VECTOR target = m_path[m_pathIndex];

		VECTOR diff = VSub(target, m_pos);

		float dist = VSize(diff);

		if (dist < 80.0f)
		{
			m_pathIndex++;
		}
		else
		{
			VECTOR norm = VNorm(diff);

			VECTOR move =
				VScale(norm, speed);

			m_pos =
				VAdd(m_pos, move);

			m_rot.y =
				atan2f(-norm.x, -norm.z);
		}

		if (m_hp <= 0)
		{
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

void CGoblin::Draw() {
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
		DrawSphere3D(GetCenter(), GOBLIN_RADIUS, 8, RED, RED, true);
	}
}

void CGoblin::Exit() {
	if (m_hndl != -1) {
		MV1DeleteModel(m_hndl);

		m_hndl = -1;

	}
}

void CGoblin::Request(VECTOR pos) {

	m_isActive = true;

	m_pos = pos;

	m_hp = GOBLIN_HP;

	m_pathIndex = 0;

}

VECTOR CGoblin::GetCenter() {
	VECTOR center = m_pos;
	center.y += GOBLIN_RADIUS;
	return center;

}

void CGoblin::HitDamage()
{
	m_isDamage = true;

	m_damageTime = 4;

}

void CGoblin::SetFire() {
	m_isFire = true;
	m_fireTime = 180;
	m_hp -= 0.2f;
}

void CGoblin::KnockBack(VECTOR vec) {
	m_knockPow = VScale(vec, 3);
	m_knockTime = 30;
	m_isKnock = true;
}

void CGoblin::Reset() {
	m_hp = GOBLIN_HP;
	m_isActive = false;
	m_isKnock = false;
	m_isFire = false;
	m_isDamage = false;
	m_isDeath = false;
}

void CGoblin::SetPath(const vector<VECTOR>& path) {
	m_path = path;
	m_pathIndex = 0;
}
