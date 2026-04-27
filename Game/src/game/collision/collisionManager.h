#pragma once
#include"../../lib/collision/collision.h"
#include"../Player/Player.h"
#include"../stage/field/field.h"
#include"../Camera/CameraManager.h"

class CCollisionManager {
public:
	static void CheckHitPlayerToStage(CPlayer& player,CField& field);

	static VECTOR CheckHitEyeToStage(CPlayer& player, CField& field,CameraManager& camera);
};