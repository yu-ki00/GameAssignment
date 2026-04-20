#pragma once
#include"../common.h"
#include<DxLib.h>
#include"../../lib/Object/Object3D.h"

static const VECTOR PLAYER_SIZE = { 15.0f,15.0f,15.0f };
static const char PLAYER_MODEL_PATH[] = { "" };
static const float PLAYER_SPEED = 10;
static const float PLAYER_RADIUS = 10;
static const float JUMP_POWER = 10;
static const VECTOR START_POS = { 0,0,0 };
static const float JUMP_SPEED = 100.0f;	//ジャンプ速度
const float MOVE_ACCEL = 800.0f;		//移動加速度
const float FRICTION = 5.0f;			//地面摩擦
static const float MAX_SPEED = 100.0f;	//最大速度
static const float AIR_DRAG = 8.0f;		//空気抵抗係数
static const int INETIALBOOST = 200;	//慣性ジャンプ
static const float ANIM_SPD = 1.0f;
static const int INERTIAL_BOOST = 150.0f;

class CPlayer :public CObject3D {
private:
	VECTOR m_speed;		//移動速度

	VECTOR m_size;		//プレイヤーサイズ

	bool m_isGround;	//着地しているか

	float m_jumpPower;

	VECTOR m_velocity;	//速度ベクトル

	float m_Accel;		//加速度

	void MoveExec(float dt);

	void JumpExec();
public:
	CPlayer();
	~CPlayer();
	//初期化
	void Init();

	//モデルロード
	void Load();

	//毎フレームする処理
	void Step(VECTOR camerarot,float dt);

	VECTOR GetTop() { return VGet(m_pos.x, m_pos.y + m_size.y, m_pos.z); }

	VECTOR GetCenter();

	bool GetIsGround() { return m_isGround; }

	void SetIsGround(bool isGround) { m_isGround = isGround; }
};