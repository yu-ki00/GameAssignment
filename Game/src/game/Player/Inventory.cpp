#include "Inventory.h"
#include"../common.h"
void CInventory::Init() {
	m_gold = 1000;
	m_trapNumber = Spike;
	for (int i = 0;i < TrapNum;i++) {
		m_trap[i].m_hndl = -1;
			for (int j = 0;j < i;j++) {
				m_trap[j].m_pos.x -= 50;
			}
		if (i == 0) {
			m_trap[i].m_pos = VGet(WINDOW_SIZE_X/2, 700, 0);
		}
		else {
			m_trap[i].m_pos = VGet(m_trap[i - 1].m_pos.x + 100, 700, 0);
		}

	}
}

void CInventory::Load() {
	for (int i = 0;i < TrapNum;i++) {
		m_trap[i].m_hndl = LoadGraph(TRAP_GRAPH_PATH[i]);
	}
}

void CInventory::Step() {
	int wheel = GetMouseWheelRotVol();
	if (wheel > 0) {
		switch (m_trapNumber)
		{
		case Spike:
			m_trapNumber = Net;
			break;
		case Net:
			m_trapNumber = Fire;
			break;
		case Fire:
			m_trapNumber = Spike;
			break;
		default:
			break;
		}
	}
	if (wheel < 0) {
		switch (m_trapNumber)
		{
		case Spike:
			m_trapNumber = Fire;
			break;
		case Net:
			m_trapNumber = Spike;
			break;
		case Fire:
			m_trapNumber = Net;
			break;
		default:
			break;
		}
	}
}

void CInventory::Draw() {
	DrawFormatString(WINDOW_SIZE_X / 2, 10, RED, "%d", m_trapNumber);
	for (int i = 0;i < TrapNum;i++) {
		DrawRotaGraph(m_trap[i].m_pos.x, m_trap[i].m_pos.y, 1.0f, 0.0f, m_trap[i].m_hndl, true);
		float p = 5.0f;
		if (i == m_trapNumber) {
			p = 10.0f;
		}
		DrawBoxAA(m_trap[i].m_pos.x - 50, m_trap[i].m_pos.y - 50, m_trap[i].m_pos.x + 50, m_trap[i].m_pos.y + 50, WHITE, false,p);
	}

	DrawFormatString(1000, 50, GetColor(255, 255, 0), "%d", m_gold);

}

void CInventory::Exit() {
	for (int i = 0;i < TrapNum;i++) {

		if (m_trap[i].m_hndl != -1) {

			DeleteGraph(m_trap[i].m_hndl);

			m_trap[i].m_hndl = -1;
		}
	}
}

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

void CInventory::Reset() {
	m_gold = 1000;
}