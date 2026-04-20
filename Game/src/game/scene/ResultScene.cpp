#include"ResultScene.h"
#include"../collision/CollisionManager.h"
#include"../../lib/input/PadInput.h"
#include"../../lib/input/input.h"
#include"../common.h"


//----------------------
// コンストラクタ
//----------------------
CResultScene::CResultScene()
{

	m_state = INIT;

}

//----------------------
// デストラクタ
//----------------------
CResultScene::~CResultScene()
{

	// 安全のためにデータ破棄処理を呼び出し
	Exit();

}

int CResultScene::Loop() {
	return CSceneBase::Loop();
}

//----------------------
// 描画処理
//----------------------
void CResultScene::Draw()
{
	switch (m_state)
	{
	case CResultScene::INIT:
		break;
	case CResultScene::LOAD:
		break;
	case CResultScene::MAIN:
		DrawFormatString(10, 10, RED, "リザルト");
		DrawRotaGraph(WINDOW_SIZE_X / 2, WINDOW_SIZE_Y / 2, 1.0f, 0.0f, m_hndl, true);
		break;
	case CResultScene::END:
		break;
	default:
		break;
	}


}

//----------------------
// 初期化
//----------------------
void CResultScene::Init()
{

	m_hndl = -1;

}

//----------------------
// データロード
//----------------------
void CResultScene::Load()
{



}

//----------------------
// タイトルのメイン処理
//----------------------
int CResultScene::Step()
{

	CInput::Update();
	switch (m_state)
	{
	case CResultScene::INIT:
		break;
	case CResultScene::LOAD:
		break;
	case CResultScene::MAIN:
		if (CInput::IsTrg(KEY_JUMP) || CGamePad::IsPadPush(DX_INPUT_PAD1, BUTTON_B)) {

			m_state = END;

			return 1;

		}
		break;

	case CResultScene::END:

		break;
	default:
		break;
	}
	return -1;
}

//----------------------
//	終了処理
//----------------------
void CResultScene::Exit()
{
	if (m_hndl != -1) {

		DeleteGraph(m_hndl);

		m_hndl = -1;

	}

}