#pragma once
#include<DxLib.h>
#include"scenebase.h"

static const char TITLE_PATH[] = { "Data/graphics/Title.png" };
static const char CONTROL_PATH[] = { "Data/graphics/controler.png" };
static const char KEYBOARD_PATH[] = { "Data/graphics/keybord.png" };
static const int END_WAIT = 1;
class CTitleScene :CSceneBase{
private:

	int m_hndl;
	int m_keyboard_hndl;
	int m_controler_hndl;
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