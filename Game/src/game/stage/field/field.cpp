#include"field.h"

CField::CField() {
	Init();
}

CField::~CField() {
	Exit();
}

void CField::Init() {
	CObject3D::Init();
	m_pos.y = -20;
}

void CField::Load() {
	if(m_hndl==-1)
	m_hndl = MV1LoadModel(FIELD_PATH);
	MV1SetupCollInfo(m_hndl);	// ƒRƒŠƒWƒ‡ƒ“î•ñ\’z

}

void CField::Step() {

}

void CField::Draw() {
	CObject3D::Draw();
}

void CField::Exit() {
	CObject3D::Exit();
}