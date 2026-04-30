#include"collisionManager.h"
void CCollisionManager::CheckHitPlayerToStage(CPlayer& player,CField& field) {
	bool isGround=false;
	VECTOR result{ 0.0f };
	bool isHitFlag = false;
	VECTOR pl_pos = player.GetPos();
	float pl_rad = PLAYER_RADIUS;
	float scale = 0.0f;
	int hndl = field.GetHndl();
	//当たり判定情報が格納される構造体
	MV1_COLL_RESULT_POLY_DIM col;

	col = MV1CollCheck_Sphere(field.GetHndl(), -1, pl_pos, pl_rad);

	if (col.HitNum != 0) {

		isHitFlag = true;

		VECTOR nownorm = { 0 };

		float nowsize = 0.0f;

		for (int i = 0; i < col.HitNum; i++) {

			VECTOR Normal = col.Dim[i].Normal;

			VECTOR v = VSub(pl_pos, col.Dim[i].HitPosition);
			float len = VSize(v);

			len = pl_rad - len;

			v = VScale(Normal, len);

			nownorm = VAdd(nownorm, v);
			if (Normal.y >= 0.5) {



				isGround = true;
			}
			else if (Normal.y <= -0.7) {

			}

			nowsize = VSize(result);

			if (nowsize >= scale) {

				result = nownorm;

				result.y = result.y;

				scale = nowsize;
			}
			if (isGround) {
				player.SetIsGround(true);
			}
			else
				player.SetIsGround(false);
		}
	}
	else
		player.SetIsGround(false);
	MV1CollResultPolyDimTerminate(col);
}

VECTOR CCollisionManager::CheckHitEyeToStage(CPlayer& player, CField& field, CameraManager& camera) {
	bool isHit = false;

	//カメラマネージャーからプレイカメラを取得
	PlayCamera& play = camera.GetPlay();

	//カメラの現在地を取得
	VECTOR eye_pos = play.GetTarget();

	//カメラの視線の終点を取得
	VECTOR eye_end = VAdd(eye_pos,VScale(play.GetVec(), 300));

	//当たり判定情報が格納される構造体
	MV1_COLL_RESULT_POLY col;

	//カメラの視線とステージの当たり判定
	col = MV1CollCheck_Line(field.GetHndl(), -1, eye_pos, eye_end);

	if (col.HitFlag) {
		//衝突地点を取得して値を返す
		return col.HitPosition;
	}

}