#pragma once
#include"../common.h"
#include<DxLib.h>
#include"../../lib/Object/Object3D.h"

static const VECTOR PLAYER_SIZE = { 15.0f,15.0f,15.0f };
static const char PLAYER_MODEL_PATH[] = { "" };
static const float PLAYER_SPEED = 10;
static const float PLAYER_RADIUS = 10;
static const float JUMP_POWER = 10;


class CPlayer :public CObject3D {
private:
	VECTOR m_speed;		//移動速度

	VECTOR m_size;		//プレイヤーサイズ

	bool m_isGround;	//着地しているか

	float m_jumpPower;

	void MoveExec();
public:
	CPlayer();
	~CPlayer();
	//初期化
	void Init();

	//モデルロード
	void Load();

	//毎フレームする処理
	void Step(VECTOR rot);

	VECTOR GetTop() { return VGet(m_pos.x, m_pos.y + m_size.y, m_pos.z); }

	VECTOR GetCeneter() { return VGet(m_pos.x, m_pos.y + m_size.y / 2, m_pos.z); }

	bool GetIsGround() { return m_isGround; }

	void SetIsGround(bool isGround) { m_isGround = isGround; }
};