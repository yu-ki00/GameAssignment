#pragma once
#include"../Player/Player.h"
#include"../Camera/CameraManager.h"
#include"../stage/sky/sky.h"
#include"../stage//field/field.h"
#include"scenebase.h"
#include"../Trap/SpikeManager.h"
#include"../Enemy/EnemyManager.h"
#include"../Player/Inventory.h"

class CPlayScene :CSceneBase{
private:

	int m_hndl;

	int m_time;

	CameraManager m_camera;

	CPlayer m_player;

	CSky m_sky;

	CField m_field;

	CSpikeManager m_spike;

	CEnemyManager m_enemy;

	CInventory m_inventory;

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