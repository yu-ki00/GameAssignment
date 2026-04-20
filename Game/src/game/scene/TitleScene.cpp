#include"TitleScene.h"
#include"../collision/CollisionManager.h"
#include"../../lib/input/PadInput.h"
#include"../../lib/input/input.h"
#include"../common.h"


//----------------------
// コンストラクタ
//----------------------
CTitleScene::CTitleScene()
{

	m_state = INIT;

}

//----------------------
// デストラクタ
//----------------------
CTitleScene::~CTitleScene()
{

	// 安全のためにデータ破棄処理を呼び出し
	Exit();

}

int CTitleScene::Loop() {
	return CSceneBase::Loop();
}

//----------------------
// 描画処理
//----------------------
void CTitleScene::Draw()
{
	switch (m_state)
	{
	case CTitleScene::INIT:
		break;
	case CTitleScene::LOAD:
		break;
	case CTitleScene::MAIN:
		DrawFormatString(10, 10, RED, "タイトル");
		DrawRotaGraph(WINDOW_SIZE_X / 2, WINDOW_SIZE_Y / 2, 1.0f, 0.0f, m_hndl, true);
		break;
	case CTitleScene::END:
		break;
	default:
		break;
	}


}

//----------------------
// 初期化
//----------------------
void CTitleScene::Init()
{

	m_endwait = 0;
	m_hndl = -1;
	m_keyboard_hndl = -1;
	m_controler_hndl = -1;

}

//----------------------
// データロード
//----------------------
void CTitleScene::Load()
{
	if (m_hndl == -1) {

		m_hndl = LoadGraph(TITLE_PATH);

	}
	if (m_keyboard_hndl == -1)
	{
		m_keyboard_hndl = LoadGraph(KEYBOARD_PATH);
	}
	if (m_controler_hndl == -1) {
		m_controler_hndl = LoadGraph(CONTROL_PATH);
	}



}

//----------------------
// タイトルのメイン処理
//----------------------
int CTitleScene::Step()
{

	CInput::Update();
	switch (m_state)
	{
	case CTitleScene::INIT:
		break;
	case CTitleScene::LOAD:
		break;
	case CTitleScene::MAIN:

		if (CInput::IsTrg(KEY_JUMP) || CGamePad::IsPadPush(DX_INPUT_PAD1, BUTTON_B)) {

			m_state = END;
			return 1;

		}

		break;
	case CTitleScene::END:



		break;
	default:
		break;
	}
	return -1;
}

//----------------------
//	終了処理
//----------------------
void CTitleScene::Exit()
{
	if (m_hndl != -1) {

		DeleteGraph(m_hndl);

		m_hndl = -1;

	}

}