#include "Inventory.h"
#include"../common.h"
void CInventory::Init() {
	m_gold = 500;
	m_trapNumber = Spike;
}

void CInventory::Load() {

}

void CInventory::Step() {
	if (GetMouseWheelRotVol() > 0) {
		switch (m_trapNumber)
		{
		case Spike:
			m_trapNumber = Net;
			break;
		case Net:
			m_trapNumber = Spike;
			break;
		default:
			break;
		}
	}
	if (GetMouseWheelRotVol() < 0) {
		switch (m_trapNumber)
		{
		case Spike:
			m_trapNumber = Net;
			break;
		case Net:
			m_trapNumber = Spike;
			break;
		default:
			break;
		}
	}
}

void CInventory::Draw() {
	DrawFormatString(700, 10, RED, "%d",m_trapNumber);

}

void CInventory::Exit() {

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
	default:
		break;
	}
}