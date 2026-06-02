#include"PlayScene.h"
#include"../collision/collisionManager.h"
#include"../../lib/input/PadInput.h"
#include"../../lib/input/input.h"
#include "../../lib/effekseer/effekseer.h"
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

		m_crystal.Draw();

		m_sky.Draw();

		m_trap.Draw();

		switch (m_turn)
		{
		case CPlayScene::TRAP:
			m_trap.DrawA(m_inventory.GetTrap());
			m_inventory.Draw();

			
			break;
		case CPlayScene::BATTLE:
			m_enemy.Draw();
			break;
		case CPlayScene::LAST:
			SetFontSize(128);
			DrawFormatString(500, WINDOW_SIZE_Y/2-100, RED, "GAMEOVER");
			SetFontSize(32);
			break;
		default:
			break;
		}

		CEffekseerCtrl::Draw();
#ifdef DEBUG
		auto hit = CCollisionManager::CheckHitEyeToStage(m_player, m_field, m_camera);

		

		VECTOR eye_pos = m_camera.GetPlay().GetTarget();
		VECTOR eye_end = VAdd(eye_pos, VScale(m_camera.GetPlay().GetVec(), 300));

		DrawLine3D(eye_pos, eye_end, RED);
		DrawFormatString(10, 10, RED, "ゲーム");
		DrawFormatString(10, 32, RED, "%f,%f,%f", m_player.GetTop().x, m_player.GetTop().y, m_player.GetTop().z);
		VECTOR pos = hit.position;
		DrawFormatString(10, 64, RED, "%f,%f,%f", pos.x, pos.y, pos.z);
		if(m_player.GetIsGround())
		DrawFormatString(10, 96, RED, "ついてるよ");


#endif // DEBUG




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

	m_trap.Init();

	m_field.Init();
	m_crystal.Init();

	m_enemy.Init();

	m_inventory.Init();

	m_nowTime = 0;
	m_prevTime = 0;
	dt = 0;

	m_turn = TRAP;

}

//----------------------
// データロード
//----------------------
void CPlayScene::Load()
{
	m_sky.Load();

	m_field.Load();

	m_trap.Load();
	
	m_crystal.Load(m_field.GetStartPos());

	m_enemy.Load();

	m_player.Load(m_field.GetStartPos());

	m_inventory.Load();
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
		auto hit = CCollisionManager::CheckHitEyeToStage(m_player, m_field, m_camera);
		m_trap.Step(hit.position);
		m_crystal.Step();


		switch (m_turn)
		{
		case CPlayScene::TRAP:
			m_inventory.Step();
		
			if (CInput::IsTrg(KEY_SHOT)) {
				m_inventory.SubGold();
				if (m_inventory.GetGold()>=0) {
					m_trap.Request(hit.position, hit.isHit, m_inventory.GetTrap());
				}
				else {
					m_inventory.AddGold();
				}
				

			}
			if (CInput::IsTrg(KEY_Z))
				m_turn = BATTLE;
			break;
		case CPlayScene::BATTLE:

			m_enemy.Request(m_field.GetSpawnPos());

			m_enemy.Step(m_field.GetStartPos());

			if (m_enemy.IsAllDead()) {
				m_enemy.Reset();
				m_trap.Reset();
				m_inventory.Reset();
				m_turn = TRAP;
			}
			break;
		case CPlayScene::LAST:
			if (CInput::IsTrg(KEY_Z)) {
				m_state = END;
				m_turn = TRAP;
				return 1;
			}
			break;
		default:
			break;
		}


		CCollisionManager::CheckHitPlayerToStage(m_player, m_field);
		CCollisionManager::CheckHitEnemyToSpike(m_enemy, m_trap);
		CCollisionManager::CheckHitEnemyToNet(m_enemy, m_trap);
		CCollisionManager::CheckHitEyeToEnemy(m_enemy, m_player, m_camera);
		CCollisionManager::CheckHitEnemyToStage(m_enemy, m_field);
		CCollisionManager::CheckHitEnemyToEnemy(m_enemy);
		CCollisionManager::CheckHitEnemyToFire(m_enemy, m_trap);
		CCollisionManager::CheckHitEnemyToCrystal(m_enemy, m_crystal);
		m_sky.Update();

		m_field.Update();
		
		m_trap.Update();

		m_camera.Update();

		m_crystal.Update();

		m_enemy.Update();

		if (!m_crystal.GetActive())
		{

			m_turn = LAST;

		}
		break;
	case CPlayScene::END:

		return 1;
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

	m_trap.Exit();

	m_field.Exit();

	m_enemy.Exit();

	m_crystal.Exit();

	CEffekseerCtrl::StopAll();
}