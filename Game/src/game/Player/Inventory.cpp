#include "Inventory.h"
#include"../common.h"

//初期化
void CInventory::Init() {
	m_gold = 1000;
	m_trapNumber = Net;
	for (int i = 0;i < TrapNum;i++) {
		m_trap[i].m_hndl = -1;
			for (int j = 0;j < i;j++) {
				m_trap[j].m_pos.x -= 100;
			}
		if (i == 0) {
			m_trap[i].m_pos = VGet(WINDOW_SIZE_X/2, 700, 0);
		}
		else {
			m_trap[i].m_pos = VGet(m_trap[i - 1].m_pos.x + 200, 700, 0);
		}

	}
}

//ロード
void CInventory::Load() {
	for (int i = 0;i < TrapNum;i++) {
		m_trap[i].m_hndl = LoadGraph(TRAP_GRAPH_PATH[i]);
	}
}

//毎フレーム動く処理
void CInventory::Step() {
	int wheel = GetMouseWheelRotVol();
	if (wheel > 0) {
		switch (m_trapNumber)
		{
		case Net:
			m_trapNumber = Spike;
			break;
		case Spike:
			m_trapNumber = Fire;
			break;
		case Fire:
			m_trapNumber = Net;
			break;
		default:
			break;
		}
	}
	if (wheel < 0) {
		switch (m_trapNumber)
		{
		case Net:
			m_trapNumber = Fire;
			break;
		case Spike:
			m_trapNumber = Net;
			break;
		case Fire:
			m_trapNumber = Spike;
			break;
		default:
			break;
		}
	}
}

//描画
void CInventory::Draw() {
	for (int i = 0;i < TrapNum;i++) {
		DrawRotaGraph((int)m_trap[i].m_pos.x,(int) m_trap[i].m_pos.y, 0.4f, 0.0f, m_trap[i].m_hndl, true);
		float p = 5.0f;
		if (i == m_trapNumber) {
			p = 10.0f;
		}
		DrawBoxAA(m_trap[i].m_pos.x - 100, m_trap[i].m_pos.y - 100, m_trap[i].m_pos.x + 100, m_trap[i].m_pos.y + 100, WHITE, false,p);
	}

	DrawFormatString(1000, 50, GetColor(255, 255, 0), "%d G", m_gold);

}

//終了
void CInventory::Exit() {
	for (int i = 0;i < TrapNum;i++) {

		if (m_trap[i].m_hndl != -1) {

			DeleteGraph(m_trap[i].m_hndl);

			m_trap[i].m_hndl = -1;
		}
	}
}

//ゴールドを減らす
void CInventory::SubGold() {
	switch (m_trapNumber)
	{
	case Spike:
		m_gold -= 200;
		break;
	case Net:
		m_gold -= 100;
		break;
	case Fire:
		m_gold -= 300;
		break;
	default:
		break;
	}
}

//ゴールドを増やす
void CInventory::AddGold() {
	switch (m_trapNumber)
	{
	case Spike:
		m_gold += 200;
		break;
	case Net:
		m_gold += 100;
		break;
	case Fire:
		m_gold += 300;
		break;
	default:
		break;
	}
}

//リセット
void CInventory::Reset() {
	m_gold = 1000;
}