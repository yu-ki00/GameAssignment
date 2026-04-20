#include"Player.h"
#include"../../lib/input/input.h"
#include"math.h"
#include"../../lib/MyMath/MyMath.h"
CPlayer::CPlayer() {
	Init();
}

CPlayer::~CPlayer() {
	Exit();
}

void CPlayer::Init() {
	m_rot = ZERO;
	m_pos = ZERO;
	m_size = VGet(10, 20, 10);
	m_jumpPower = 0.0f;
}

void CPlayer::Load() {
	m_hndl = MV1LoadModel(PLAYER_MODEL_PATH);
}

void CPlayer::Step(VECTOR rot) {
	
	m_rot.y = rot.y;
	MoveExec();


	if (!m_isGround) {
		m_jumpPower-=1;
	}
	if (m_isGround) {
		m_jumpPower = 0;
	}
	if (CInput::IsTrg(KEY_JUMP)) {
		m_jumpPower = JUMP_POWER;
	}
	m_pos.y += m_jumpPower;
}


void CPlayer::MoveExec() {
	float SPEED = 0.0f;
	float move_vec = 0.0f;
	if (CInput::IsRep(KEY_UP) && CInput::IsRep(KEY_RIGHT)) {

		SPEED = PLAYER_SPEED;

		float move_deg = 45.0f;

		move_vec = DegRad(move_deg);


	}
	else if (CInput::IsRep(KEY_UP) && CInput::IsRep(KEY_LEFT)) {

		SPEED = -PLAYER_SPEED;

		float move_deg = 135.0f;

		move_vec = DegRad(move_deg);
	}

	else if (CInput::IsRep(KEY_DOWN) && CInput::IsRep(KEY_RIGHT)) {

		SPEED = PLAYER_SPEED;

		float move_deg = 135.0f;

		move_vec = DegRad(move_deg);

	}

	else if (CInput::IsRep(KEY_DOWN) && CInput::IsRep(KEY_LEFT)) {

		SPEED = -PLAYER_SPEED;

		float move_deg = 45.0f;

		move_vec = DegRad(move_deg);

	}

	else if (CInput::IsRep(KEY_UP))
	{

		SPEED = PLAYER_SPEED;
	}

	else if (CInput::IsRep(KEY_DOWN))
	{
		SPEED = -PLAYER_SPEED;
	}

	else if (CInput::IsRep(KEY_RIGHT))
	{
		SPEED = PLAYER_SPEED;

		float move_deg = 90.0f;

		move_vec = DegRad(move_deg);

	}

	else if (CInput::IsRep(KEY_LEFT))
	{
		SPEED = -PLAYER_SPEED;

		float move_deg = 90.0f;

		move_vec = DegRad(move_deg);

	}

	m_pos.x += (sinf(m_rot.y + move_vec) * SPEED);

	m_pos.y = 0.0f;

	m_pos.z += (cosf(m_rot.y + move_vec) * SPEED);
}