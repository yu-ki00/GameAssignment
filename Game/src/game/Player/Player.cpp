#include"Player.h"
#include"../../lib/input/PadInput.h"
#include"../../lib/input/input.h"
#include"../../lib/MyMath/MyMath.h"
#include"../collision/CollisionManager.h"
#include"string.h"

using namespace std;

CPlayer::CPlayer() {
	Init();
}
CPlayer::~CPlayer() {
	Exit();
}
//初期化
void CPlayer::Init() {

	m_size = PLAYER_SIZE;

	m_velocity = ZERO;

	m_Accel = 0.0f;

	m_isGround = false;

	m_pos = START_POS;


}
//モデルのロード
void CPlayer::Load() {
	if (m_hndl == -1) {



	}
}
//毎フレーム呼び出す処理
void CPlayer::Step(VECTOR camera_rot, float dt) {

	VECTOR vec = ZERO;


	m_speed = ZERO;

	//常にカメラが向いているほうを向く

	m_rot.y = camera_rot.y;

	MoveExec(dt);



}




//プレイヤーの中心座標
VECTOR CPlayer::GetCenter() {

	VECTOR center = m_pos;

	center.y = m_pos.y + (m_size.y / 2);

	return center;

}
//プレイヤー移動処理
void CPlayer::MoveExec(float dt) {

	float ACCEL = 0.0f; //加速度
	float move_vec = 0.0f;
	bool isMove = false;

	if (CGamePad::Stick(STICK_LX_POS) != 0
		|| CGamePad::Stick(STICK_LX_NEG) != 0
		|| CGamePad::Stick(STICK_LY_POS) != 0
		|| CGamePad::Stick(STICK_LY_NEG) != 0) {

		ACCEL = -MOVE_ACCEL;

		move_vec = CGamePad::StickRot(STICK_LEFT);

	}
	if (CInput::IsRep(KEY_UP) && CInput::IsRep(KEY_RIGHT)) {

		ACCEL = -MOVE_ACCEL;

		float move_deg = 45.0f;

		move_vec = DegRad(move_deg);


	}
	else if (CInput::IsRep(KEY_UP) && CInput::IsRep(KEY_LEFT)) {

		ACCEL = MOVE_ACCEL;

		float move_deg = 135.0f;

		move_vec = DegRad(move_deg);
	}

	else if (CInput::IsRep(KEY_DOWN) && CInput::IsRep(KEY_RIGHT)) {

		ACCEL = -MOVE_ACCEL;

		float move_deg = 135.0f;

		move_vec = DegRad(move_deg);

	}

	else if (CInput::IsRep(KEY_DOWN) && CInput::IsRep(KEY_LEFT)) {

		ACCEL = MOVE_ACCEL;

		float move_deg = 45.0f;

		move_vec = DegRad(move_deg);

	}

	else if (CInput::IsRep(KEY_UP))
	{

		ACCEL = -MOVE_ACCEL;
	}

	else if (CInput::IsRep(KEY_DOWN))
	{
		ACCEL = MOVE_ACCEL;
	}

	else if (CInput::IsRep(KEY_RIGHT))
	{
		ACCEL = -MOVE_ACCEL;

		float move_deg = 90.0f;

		move_vec = DegRad(move_deg);

	}

	else if (CInput::IsRep(KEY_LEFT))
	{
		ACCEL = MOVE_ACCEL;

		float move_deg = 90.0f;

		move_vec = DegRad(move_deg);

	}
	if (ACCEL != 0) {
		isMove = true;
	}
	m_speed.x += (sinf(m_rot.y + move_vec) * ACCEL);

	m_speed.y = 0.0f;

	m_speed.z += (cosf(m_rot.y + move_vec) * ACCEL);

	JumpExec();

	if (!m_isGround) {
		//空中では重力と空気抵抗を受ける
		m_speed.y = -G;

		m_velocity.x -= m_velocity.x * AIR_DRAG * dt;

		m_velocity.z -= m_velocity.z * AIR_DRAG * dt;

	}
	else {
		//地上では摩擦を受ける
		m_speed.y = 0.0f;

		m_velocity.x -= m_velocity.x * FRICTION * dt;

		m_velocity.z -= m_velocity.z * FRICTION * dt;

	}

	m_velocity.x += m_speed.x * dt;

	m_velocity.y += m_speed.y * dt;

	m_velocity.z += m_speed.z * dt;

	VECTOR horiz = VGet(m_velocity.x, 0.0f, m_velocity.z);

	float speed = VSize(horiz);

	//速度を制限する
	if (speed > MAX_SPEED) {

		VECTOR limited = VScale(VNorm(horiz), MAX_SPEED);

		m_velocity.x = limited.x;

		m_velocity.z = limited.z;

	}

	//移動後の位置を加算する

	m_pos = VAdd(m_pos, VScale(m_velocity, dt));


}

//ジャンプ処理
void CPlayer::JumpExec() {
	if ((CGamePad::IsPadPush(DX_INPUT_PAD1, BUTTON_A) || CInput::IsTrg(KEY_JUMP)) && m_isGround) {

		//Aボタンを押したらジャンプ
		m_velocity.y = JUMP_SPEED;

	}
}

