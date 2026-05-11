#pragma once
#include"../../lib/collision/collision.h"
#include"../Player/Player.h"
#include"../stage/field/field.h"
#include"../Enemy/EnemyManager.h"
#include"../Camera/CameraManager.h"
#include"../Trap/TrapManager.h"
class CCollisionManager {
public:
	struct HitResult {
		bool isHit;
		VECTOR position;
	};
	static void CheckHitPlayerToStage(CPlayer& player,CField& field);

	static HitResult CheckHitEyeToStage(CPlayer& player, CField& field,CameraManager& camera);

	static void CheckHitEnemyToSpike(CEnemyManager& enemy, CTrapManager& spike);
};