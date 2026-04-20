#pragma once
#include"../Player/Player.h"
#include"../Camera/CameraManager.h"
#include"../stage/sky/sky.h"
#include"../stage//field/field.h"
#include"scenebase.h"


class CPlayScene :CSceneBase{
private:
	int m_hndl;
	int m_time;
	CameraManager m_camera;
	CPlayer m_player;
	CSky m_sky;
	CField m_field;

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