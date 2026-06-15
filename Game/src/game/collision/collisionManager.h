#pragma once
#include"../../lib/collision/collision.h"
#include"../Player/Player.h"
#include"../stage/field/field.h"
#include"../Enemy/GoblinManager.h"
#include"../Camera/CameraManager.h"
#include"../Trap/SpikeManager.h"
#include"../Player/Inventory.h"
#include"../Trap/TrapManager.h"
#include"../stage/crystal/crystal.h"
#include"../Enemy/EnemyManager.h"
class CCollisionManager {
public:
	struct HitResult {
		bool isHit;
		VECTOR position;
	};
	static void CheckHitPlayerToStage(CPlayer& player,CField& field);

	static HitResult CheckHitEyeToStage(CPlayer& player, CField& field,CameraManager& camera);

	static void CheckHitEnemyToSpike(CGoblinManager& enemy, CTrapManager& trap);

	static void CheckHitEnemyToNet(CGoblinManager& enemy, CTrapManager& trap);

	static void CheckHitEnemyToFire(CGoblinManager& enemy, CTrapManager& trap);

	static void CheckHitEyeToEnemy(CGoblinManager& enemy, CPlayer& player, CameraManager& camera);

	static void CheckHitEnemyToStage(CGoblinManager& enemy, CField& field);

	static void CheckHitEnemyToEnemy(CGoblinManager& enemy);

	static void CheckHitEnemyToCrystal(CGoblinManager& enemy,CCrystal& crystal);


};