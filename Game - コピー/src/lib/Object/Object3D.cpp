#include"Object3D.h"
#include"../../game/common.h"

CObject3D::CObject3D() {

	m_pos = ZERO;

	m_rot = ZERO;

	m_scale = { 1.0f,1.0f,1.0f };

	m_hndl = -1;

}
void CObject3D::Init() {

	m_pos = ZERO;

	m_rot = ZERO;

	m_scale = { 1.0f,1.0f,1.0f };

	m_hndl = -1;
	
	m_isActive = true;

}
void CObject3D::Update() {

	MV1SetPosition(m_hndl, m_pos);

	MV1SetScale(m_hndl, m_scale);

	MV1SetRotationXYZ(m_hndl, m_rot);

}
void CObject3D::Draw() {
	if (m_isActive) {

		MV1DrawModel(m_hndl);

	}
}
void CObject3D::Exit() {
	if (m_hndl != -1) {

		MV1DeleteModel(m_hndl);

		m_hndl = -1;

	}
}