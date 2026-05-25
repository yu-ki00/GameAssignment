#pragma once
#include"../Player/Player.h"
#include"../Camera/CameraManager.h"
#include"../stage/sky/sky.h"
#include"../stage//field/field.h"
#include"scenebase.h"
#include"../Trap/SpikeManager.h"
#include"../Enemy/EnemyManager.h"
#include"../Player/Inventory.h"
#include"../Trap/TrapManager.h"
#include"../stage/crystal/crystal.h"

class CPlayScene :CSceneBase{
private:
	enum tagState {
		TRAP,
		BATTLE,
		LAST,
	};

	int m_hndl;

	int m_time;

	CameraManager m_camera;

	CPlayer m_player;

	CSky m_sky;

	CField m_field;

	CSpikeManager m_spike;

	CEnemyManager m_enemy;

	CInventory m_inventory;

	CTrapManager m_trap;

	CCrystal m_crystal;

	float dt;

	int m_prevTime;

	int m_nowTime;

	tagState m_turn;

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