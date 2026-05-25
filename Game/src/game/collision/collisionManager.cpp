#include"collisionManager.h"
#include"../../lib/input/input.h"
void CCollisionManager::CheckHitPlayerToStage(CPlayer& player, CField& field) {

	bool isGround = false;
	VECTOR result = VGet(0, 0, 0);

	VECTOR pl_pos = player.GetPos();
	float pl_rad = PLAYER_RADIUS;

	float maxPush = 0.0f;

	VECTOR pos = pl_pos;

	for (int loop = 0; loop < 3; loop++) {

		VECTOR totalPush = VGet(0, 0, 0);

		for (auto& data : field.GetStage()) {

			if (!data.m_isActive) continue;
			float len = VSize(VSub(pos, data.m_pos));
			if (len > 200)continue;

			MV1_COLL_RESULT_POLY_DIM col;
			col = MV1CollCheck_Sphere(data.m_hndl, -1, pos, pl_rad);

			if (col.HitNum != 0) {

				for (int i = 0; i < col.HitNum; i++) {

					VECTOR Normal = col.Dim[i].Normal;

					VECTOR v = VSub(pos, col.Dim[i].HitPosition);
					float len = VSize(v);

					len = pl_rad - len;

					VECTOR push = VScale(Normal, len);

					totalPush = VAdd(totalPush, push);

					if (Normal.y >= 0.5f) {
						isGround = true;
					}
				}
				MV1CollResultPolyDimTerminate(col);
			}


		}
		totalPush.y = (int)totalPush.y;

		pos = VAdd(pos, totalPush);
	}
	// プレイヤーを押し出す
	player.SetPos(pos);

	// 接地判定
	player.SetIsGround(isGround);
}

CCollisionManager::HitResult CCollisionManager::CheckHitEyeToStage(CPlayer& player, CField& field, CameraManager& camera) {
	bool isHit = false;

	//カメラマネージャーからプレイカメラを取得
	PlayCamera& play = camera.GetPlay();

	//カメラの現在地を取得
	VECTOR eye_pos = play.GetTarget();

	//カメラの視線の終点を取得
	VECTOR eye_end = VAdd(eye_pos, VScale(play.GetVec(), 300));
	for (int tileID = 0; tileID < 3; tileID++) {

		VECTOR totalPush = VGet(0, 0, 0);

		for (auto& data : field.GetStage()) {
			float len = VSize(VSub(eye_pos, data.m_pos));
			if (len > 300)continue;

			if (!data.m_isActive) continue;
			//当たり判定情報が格納される構造体
			MV1_COLL_RESULT_POLY col;

			//カメラの視線とステージの当たり判定
			col = MV1CollCheck_Line(data.m_hndl, -1, eye_pos, eye_end);

			if (col.HitFlag) {
				//衝突地点を取得して値を返す

				return { true, data.m_pos };
			}

		}
	}
	return { false, VGet(0.0f, 0.0f, 0.0f) };

}

void CCollisionManager::CheckHitEnemyToSpike(CEnemyManager& enemy, CTrapManager& trap) {
	for (int enemyID = 0;enemyID < ENEMY_NUM;enemyID++) {
		CEnemy& OneEne = enemy.GetEnemy(enemyID);
		if (!OneEne.GetActive())continue;
		if (OneEne.GetIsDamage())continue;
		VECTOR ene_pos = OneEne.GetPos();


		for (int spikeID = 0;spikeID < SPIKE_NUM;spikeID++) {

			CSpike& OneSpi = trap.GetSpike(spikeID);

			if (!OneSpi.GetActive())continue;

			MV1_COLL_RESULT_POLY_DIM col;

			col = MV1CollCheck_Sphere(OneSpi.GetHndl(), -1, ene_pos, ENEMY_RADIUS);

			VECTOR aa = MV1GetPosition(OneSpi.GetHndl());

			if (col.HitNum != 0) {

				OneEne.SubHp(1);

				OneEne.HitDamage();

				MV1CollResultPolyDimTerminate(col);

			}

		}
	}

}

void CCollisionManager::CheckHitEnemyToNet(CEnemyManager& enemy, CTrapManager& trap) {
	for (int enemyID = 0;enemyID < ENEMY_NUM;enemyID++) {
		CEnemy& OneEne = enemy.GetEnemy(enemyID);
		if (!OneEne.GetActive())continue;
		VECTOR ene_pos = OneEne.GetPos();


		for (int netID = 0; netID < NET_NUM; netID++) {

			CNet& OneNet = trap.GetNet(netID);

			if (!OneNet.GetActive())continue;

			MV1_COLL_RESULT_POLY_DIM col;

			col = MV1CollCheck_Sphere(OneNet.GetHndl(), -1, ene_pos, ENEMY_RADIUS);

			VECTOR aa = MV1GetPosition(OneNet.GetHndl());

			if (col.HitNum != 0) {

				OneEne.SetSlow(true);

				MV1CollResultPolyDimTerminate(col);
				break;

			}
			else {
				OneEne.SetSlow(false);
			}

		}
	}

}

void CCollisionManager::CheckHitEnemyToFire(CEnemyManager& enemy, CTrapManager& trap) {
	for (int enemyID = 0; enemyID < ENEMY_NUM; enemyID++) {
		CEnemy& OneEne = enemy.GetEnemy(enemyID);
		if (!OneEne.GetActive())continue;
		VECTOR ene_pos = OneEne.GetPos();


		for (int fireID = 0; fireID < FIRE_NUM; fireID++) {

			CFire& OneFire = trap.GetFire(fireID);

			if (!OneFire.GetActive())continue;

			MV1_COLL_RESULT_POLY_DIM col;

			col = MV1CollCheck_Sphere(OneFire.GetHndl(), -1, ene_pos, ENEMY_RADIUS);

			VECTOR aa = MV1GetPosition(OneFire.GetHndl());

			if (col.HitNum != 0) {

				OneEne.SetFire();

				MV1CollResultPolyDimTerminate(col);
				break;

			}

		}
	}

}


void CCollisionManager::CheckHitEyeToEnemy(CEnemyManager& enemy, CPlayer& player, CameraManager& camera) {

	bool isHit = false;

	int EnemyID = 0;

	int NearEnemy = 0;

	float min = 999.9f;

	VECTOR knockVec = ZERO;
	//カメラマネージャーからプレイカメラを取得
	PlayCamera& play = camera.GetPlay();

	//カメラの現在地を取得
	VECTOR eye_pos = play.GetTarget();

	//カメラの視線の終点を取得
	VECTOR eye_end = VAdd(eye_pos, VScale(play.GetVec(), 300));
	
	for (int enemyID = 0;enemyID < ENEMY_NUM;enemyID++) {

		CEnemy& OneEne = enemy.GetEnemy(enemyID);

		if (!OneEne.GetActive())continue;
		if (OneEne.GetIsDamage())continue;

		VECTOR ene_pos = OneEne.GetCenter();

		if (Collision::CheckHitLineToSphere(ene_pos, ENEMY_RADIUS, eye_pos, eye_end)) {

			VECTOR vec = VSub(eye_end, eye_pos);
			VECTOR diff = VSub(ene_pos, eye_pos);
			float len = VSize(diff);
			vec = VNorm(vec);
			vec.y = 0.0f;
			if (len < min) {
				min = len;
				NearEnemy = enemyID;
				knockVec = vec;
			}
		}
	}
	if (CInput::IsTrg(KEY_SHOT)) {
		enemy.GetEnemy(NearEnemy).KnockBack(knockVec);
	}
}

void CCollisionManager::CheckHitEnemyToStage(CEnemyManager& enemy, CField& field) {

	for (int enemyID = 0;enemyID < ENEMY_NUM;enemyID++) {

		bool isGround = false;
		CEnemy& OneEne = enemy.GetEnemy(enemyID);

		if (!OneEne.GetActive())continue;

		VECTOR ene_pos = OneEne.GetCenter();
		float ene_rad = ENEMY_RADIUS;

		float maxPush = 0.0f;

		VECTOR pos = ene_pos;

		for (int loop = 0; loop < 3; loop++) {

			VECTOR totalPush = VGet(0, 0, 0);

			for (auto& data : field.GetStage()) {

				if (!data.m_isActive) continue;
				float len = VSize(VSub(pos, data.m_pos));
				if (len > 200)continue;

				MV1_COLL_RESULT_POLY_DIM col;
				col = MV1CollCheck_Sphere(data.m_hndl, -1, pos, ene_rad);

				if (col.HitNum != 0) {

					for (int i = 0; i < col.HitNum; i++) {

						VECTOR Normal = col.Dim[i].Normal;

						VECTOR v = VSub(pos, col.Dim[i].HitPosition);
						float len = VSize(v);

						len = ene_rad - len;

						VECTOR push = VScale(Normal, len);

						totalPush = VAdd(totalPush, push);

						if (Normal.y >= 0.5f) {
							isGround = true;
						}
					}
					MV1CollResultPolyDimTerminate(col);
				}


			}
			totalPush.y = (int)totalPush.y;

			pos = VAdd(pos, totalPush);

		}
		pos.y -= ENEMY_RADIUS;
		OneEne.SetPos(pos);
	
	}
}

void CCollisionManager::CheckHitEnemyToEnemy(CEnemyManager& enemy) {
	for (int i = 0; i < ENEMY_NUM; i++) {

		CEnemy& OneEne = enemy.GetEnemy(i);

		if (!OneEne.GetActive())continue;

		VECTOR enepos1 = OneEne.GetCenter();

		for (int j = 0; j < ENEMY_NUM; j++) {

			if (j == i)continue;

			CEnemy& TwoEne = enemy.GetEnemy(j);

			if (!TwoEne.GetActive())continue;

			VECTOR enepos2=TwoEne.GetCenter();

			float len = VSize(VSub(enepos2, enepos1));

			if (len > 100)continue;

			if (Collision::CheckHitSphereToSphere(enepos1, ENEMY_RADIUS, enepos2, ENEMY_RADIUS)) {
				
				VECTOR diff = VSub(enepos2,enepos1);

				float len = VSize(diff);

				if (len <= 0.0001f) continue;

				VECTOR norm = VNorm(diff);
				
				VECTOR push = VScale(norm, ENEMY_RADIUS*2);

				push = VSub(push, diff);

				push = VScale(push, 0.5f);

				OneEne.SetPos(VSub(OneEne.GetPos(), push));

				TwoEne.SetPos(VAdd(TwoEne.GetPos(), push));
			}
		}
	}
}