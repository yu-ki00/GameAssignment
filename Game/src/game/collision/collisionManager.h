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

	static void CheckHitEnemyToSpike(CEnemyManager& enemy, CTrapManager& trap);

	static void CheckHitEnemyToNet(CEnemyManager& enemy, CTrapManager& trap);

	static void CheckHitEnemyToFire(CEnemyManager& enemy, CTrapManager& trap);

	static void CheckHitEyeToEnemy(CEnemyManager& enemy, CPlayer& player, CameraManager& camera);

	static void CheckHitEnemyToStage(CEnemyManager& enemy, CField& field);

	static void CheckHitEnemyToEnemy(CEnemyManager& enemy);

	static void CheckHitEnemyToCrystal(CEnemyManager& enemy,CCrystal& crystal);
	template <typename T>
	static void CheckEnemyToStage(T& enemy, CField& field, float radius);


};