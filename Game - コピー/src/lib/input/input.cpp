#include "input.h"
#include <Dxlib.h>

typedef struct {
	unsigned int m_nowKey;
	unsigned int m_PrevKey;
}INPUT_DATA;
static INPUT_DATA g_inputData;

void CInput::Init()
{
	g_inputData.m_nowKey = g_inputData.m_PrevKey = 0;
}

void CInput::Update() {
	g_inputData.m_PrevKey = g_inputData.m_nowKey;
	g_inputData.m_nowKey = 0;
	if (CheckHitKey(KEY_INPUT_UP) || CheckHitKey(KEY_INPUT_W))g_inputData.m_nowKey |= KEY_UP;

	if (CheckHitKey(KEY_INPUT_DOWN) || CheckHitKey(KEY_INPUT_S))g_inputData.m_nowKey |= KEY_DOWN;

	if (CheckHitKey(KEY_INPUT_RIGHT) || CheckHitKey(KEY_INPUT_D))g_inputData.m_nowKey |= KEY_RIGHT;

	if (CheckHitKey(KEY_INPUT_A))g_inputData.m_nowKey |= KEY_LEFT;

	if (CheckHitKey(KEY_INPUT_RETURN))g_inputData.m_nowKey |= KEY_SELECT;

	if ((GetMouseInput() & MOUSE_INPUT_RIGHT))g_inputData.m_nowKey |= MOUSE_RIGHT;

	if (CheckHitKey(KEY_INPUT_Z) || (GetMouseInput() & MOUSE_INPUT_LEFT))g_inputData.m_nowKey |= KEY_SHOT;

	if (CheckHitKey(KEY_INPUT_SPACE))g_inputData.m_nowKey |= KEY_JUMP;

	if (CheckHitKey(KEY_INPUT_E))g_inputData.m_nowKey |= KEY_E;

	if (CheckHitKey(KEY_INPUT_Q))g_inputData.m_nowKey |= KEY_Q;

	if (CheckHitKey(KEY_INPUT_LSHIFT))g_inputData.m_nowKey |= KEY_SHIFT;

}
bool CInput::IsRep(unsigned int key)
{
	if (g_inputData.m_nowKey & key)return true;
	else return false;
}
bool CInput::IsTrg(unsigned int key) {
	if ((g_inputData.m_nowKey & key) && !(g_inputData.m_PrevKey & key)) return true;
	else return false;
}
bool CInput::IsRelease(unsigned int key) {
	if (!(g_inputData.m_nowKey & key) && (g_inputData.m_PrevKey & key)) {
		return true;
	}
	else return false;
}