#pragma once
#include"scenebase.h"
static const char RESULT_PATH[] = { "" };
class CResultScene:public CSceneBase{
private:
	int m_hndl;
	int m_time;

public:
	CResultScene();
	~CResultScene();
	int Loop();
	void Draw();
private:
	void Init();
	void Load();
	int Step();
	void Exit();
};