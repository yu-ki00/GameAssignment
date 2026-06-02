#pragma once
#include<DxLib.h>
#include"scenebase.h"

static const char TITLE_PATH[] = { "Data/graph/Title.png" };

static const int END_WAIT = 1;
class CTitleScene :CSceneBase{
private:

	int m_hndl;
	int m_endwait;

public:
	CTitleScene();
	~CTitleScene();
	int Loop();
	void Draw();
private:
	void Init();
	void Load();
	int Step();
	void Exit();
};