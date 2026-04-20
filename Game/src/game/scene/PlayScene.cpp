#include"PlayScene.h"
#include"../collision/collisionManager.h"
#include"../../lib/input/PadInput.h"
#include"../../lib/input/input.h"
#include"../common.h"


//----------------------
// コンストラクタ
//----------------------
CPlayScene::CPlayScene()
{

	m_state = INIT;

}

//----------------------
// デストラクタ
//----------------------
CPlayScene::~CPlayScene()
{

	// 安全のためにデータ破棄処理を呼び出し
	Exit();

}

int CPlayScene::Loop() {
	m_nowTime = GetNowCount();
	dt = (m_nowTime - m_prevTime) / 1000.0f;
	m_result = CSceneBase::Loop();
	m_prevTime = GetNowCount();
	return m_result;
}
//----------------------
// 描画処理
//----------------------
void CPlayScene::Draw()
{
	m_nowTime = GetNowCount();
	dt = (m_nowTime - m_prevTime) / 1000.0f;
	switch (m_state)
	{
	case CPlayScene::INIT:
		break;
	case CPlayScene::LOAD:
		break;
	case CPlayScene::MAIN:
		m_field.Draw();

		m_sky.Draw();
		DrawFormatString(10, 10, RED, "ゲーム");

		DrawFormatString(10, 32, RED, "%f,%f,%f", m_player.GetPos().x, m_player.GetPos().y, m_player.GetPos().z);
		break;
	case CPlayScene::END:
		break;
	default:
		break;
	}



}

//----------------------
// 初期化
//----------------------
void CPlayScene::Init()
{

	m_hndl = -1;

	m_camera.Init();

	m_player.Init();

	m_sky.Init();

	m_field.Init();

	m_nowTime = 0;
	m_prevTime = 0;
	dt = 0;

}

//----------------------
// データロード
//----------------------
void CPlayScene::Load()
{
	m_sky.Load();

	m_field.Load();

}

//----------------------
// ゲームのメイン処理
//----------------------
int CPlayScene::Step()
{

	CInput::Update();
	switch (m_state)
	{
	case CPlayScene::INIT:
		break;
	case CPlayScene::LOAD:
		break;
	case CPlayScene::MAIN:
		
		if (m_camera.GetID() == m_camera.ID_PLAY) {
			m_player.Step(m_camera.GetRot(),dt);

		}
		m_camera.Step(m_player.GetTop());

		m_sky.Step(m_player.GetPos());

		CCollisionManager::CheckHitPlayerToStage(m_player, m_field);
		m_sky.Update();

		m_field.Update();

		m_camera.Update();

		if (CInput::IsTrg(KEY_SELECT))
		{

			m_state = END;
			return 1;

		}
		break;

		break;
	case CPlayScene::END:

		break;
	default:
		break;
	}
	return -1;
}

//----------------------
//	終了処理
//----------------------
void CPlayScene::Exit()
{
	m_sky.Exit();

	m_field.Exit();

}