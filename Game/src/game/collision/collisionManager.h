#pragma once
#include"../../lib/collision/collision.h"
#include"../Player/Player.h"
#include"../stage/field/field.h"

class CCollisionManager {
public:
	static void CheckHitPlayerToStage(CPlayer& player,CField field);
};