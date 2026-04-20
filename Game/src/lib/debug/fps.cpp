#include <DxLib.h>		
#include"fps.h"
#include"../../game/common.h"

static const int FRAME_RATE = 60;
static const int FRAME_RATE_MILLI_SECOND = 1000 / FRAME_RATE;

double CFps::m_frameRate;
int CFps::m_count;
int CFps::m_updateFrameRateTime;
int CFps::m_currentTime;
int CFps::m_lastTime;

void CFps::Init() {
	m_count = 0;
	m_currentTime = GetNowCount();
	m_updateFrameRateTime = m_currentTime;
	m_lastTime = m_currentTime;
	m_frameRate = 0.0f;
}
//フレームを進めていいか判断
bool CFps::CheckNext()
{
	//現在の時間を取得する
	m_currentTime = GetNowCount();
	//前回の時間から今回までの差分を計算
	int difTime = m_currentTime - m_lastTime;
	//前回の時間から指定したフレーム文系化しているかチェック
	if (difTime >= FRAME_RATE_MILLI_SECOND)return true;
	else return false;
}
//フレームレート計算
void CFps::Calc() {
	//前回時間を更新
	m_lastTime = m_currentTime;
}
void CFps::PrintFps() {
	//１フレーム進んだと判断
	m_count++;
	//前回の表示時間から今回までの差分を計算
	int difTime = m_currentTime - m_updateFrameRateTime;
	//１秒が経過するまで経過はこれ以降実行しない
	if (difTime >= 1000) {
		float frameCnt = (float)(m_count * 1000);
		//フレームレートを計算
		m_frameRate = frameCnt / difTime;
		//カウント初期化
		m_count = 0;
		//フレームレート更新時間を最新に
		m_updateFrameRateTime = m_currentTime;
	}
	//FPSは常に表示を続ける
	DrawFormatString(16, 16, RED, "FPS:%.2f", m_frameRate);
}