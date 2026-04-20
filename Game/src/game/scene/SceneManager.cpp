#include"SceneManager.h"
#include"PlayScene.h"
#include"../../lib/input/input.h"
#include"../../lib/input/PadInput.h"


//----------------------
// コンストラクタ
//----------------------
SceneManager::SceneManager()
{

	m_state = TITLE;

	CInput::Init();

	CGamePad::InitGamePad();

	CGamePad::GetPadNumState();

	SetFontSize(32);

}

//----------------------
// デストラクタ
//----------------------
SceneManager::~SceneManager()
{

	// 安全のためにデータ破棄処理を呼び出し


}

//------------------------
// 毎フレーム呼ぶ処理
//------------------------
int SceneManager::Loop()
{

	// ゲームが終了したかを外部に伝えるため

	int ret = -1;



	CGamePad::StepGamePad();

	switch (m_state)
	{
	case SceneManager::TITLE:

		if (m_title.Loop() != -1) {

			m_state = SceneManager::GAME;  // 次へ進む

		}

		break;
	case SceneManager::GAME: {

		int result = 0;

		result = m_play.Loop();

		if (result == 1) {

			m_state = SceneManager::RESULT;  // 次へ進む

		}
		else if (result == 2) {

			m_state = SceneManager::TITLE;

		}

		break;
	}
	case SceneManager::RESULT:

		if (m_result.Loop() != -1) {

			m_state = SceneManager::TITLE;

		}

		break;

	default:
		break;
	}

	// 本編が終了したかどうかを外部に伝える

	return ret;
}

//----------------------
// 
//----------------------
void SceneManager::Draw()
{
	switch (m_state)
	{
	case SceneManager::TITLE:

		m_title.Draw();

		break;


	case SceneManager::GAME:

		m_play.Draw();

		break;

	case SceneManager::RESULT:

		m_result.Draw();

		break;

	default:
		break;
	}
}
