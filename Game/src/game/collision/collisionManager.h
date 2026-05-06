#pragma once
#include"../../lib/collision/collision.h"
#include"../Player/Player.h"
#include"../stage/field/field.h"
#include"../Camera/CameraManager.h"

class CCollisionManager {
public:
	struct HitResult {
		bool isHit;
		VECTOR position;
	};
	static void CheckHitPlayerToStage(CPlayer& player,CField& field);

	static HitResult CheckHitEyeToStage(CPlayer& player, CField& field,CameraManager& camera);
};