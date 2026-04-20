#include"collisionManager.h"
bool isGround;
void CCollisionManager::CheckHitPlayerToStage(CPlayer& player,CField field) {
	VECTOR result{ 0.0f };
	bool isHitFlag = false;
	VECTOR pl_pos = player.GetPos();
	float pl_rad = PLAYER_RADIUS;
	float scale = 0.0f;
	//ìñÇΩÇËîªíËèÓïÒÇ™äiî[Ç≥ÇÍÇÈç\ë¢ëÃ
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

				result.y = (int)result.y;

				scale = nowsize;
			}

		}
		if (isGround == true) {

			player.SetIsGround(true);

		}
		else {

			player.SetIsGround(false);
		}

		player.SetPos(VAdd(result, player.GetPos()));

	}
	else {
		if (isGround == true) {

			player.SetIsGround(true);

		}
		else if (isGround == false) {

			player.SetIsGround(false);

		}
	}

	MV1CollResultPolyDimTerminate(col);
}

void CCollisionManager::CheckHitPlayerToStage(CPlayer& player, CField field) {
	VECTOR result{ 0.0f };
	bool isHitFlag = false;
	VECTOR pl_pos = player.GetPos();
	float pl_rad = PLAYER_RADIUS;
	float scale = 0.0f;
	MV1_COLL_RESULT_POLY_DIM col;

	col = MV1CollCheck_Sphere(field.GetHndl(), -1, pl_pos, pl_rad);


}