#pragma once
#include"../Player/Player.h"
#include"../Camera/CameraManager.h"
#include"../stage/sky/sky.h"
#include"../stage//field/field.h"
#include"scenebase.h"
#include"../Trap/TrapManager.h"
#include"../Enemy/EnemyManager.h"

class CPlayScene :CSceneBase{
private:

	int m_hndl;

	int m_time;

	CameraManager m_camera;

	CPlayer m_player;

	CSky m_sky;

	CField m_field;

	CTrapManager m_trap;

	CEnemyManager m_enemy;

	float dt;

	int m_prevTime;

	int m_nowTime;

public:
	CPlayScene();
	~CPlayScene();
	int Loop();
	void Draw();
private:
	void Init();
	void Load();
	int Step();
	void Exit();
};