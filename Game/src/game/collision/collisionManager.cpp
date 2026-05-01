#include"collisionManager.h"
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
            }

            MV1CollResultPolyDimTerminate(col);
        }

        pos = VAdd(pos, totalPush);
    }
    // プレイヤーを押し出す
    player.SetPos(pos);

    // 接地判定
    player.SetIsGround(isGround);
}
VECTOR CCollisionManager::CheckHitEyeToStage(CPlayer& player, CField& field, CameraManager& camera) {
	bool isHit = false;

	//カメラマネージャーからプレイカメラを取得
	PlayCamera& play = camera.GetPlay();

	//カメラの現在地を取得
	VECTOR eye_pos = play.GetTarget();

	//カメラの視線の終点を取得
	VECTOR eye_end = VAdd(eye_pos,VScale(play.GetVec(), 300));
    for (int loop = 0; loop < 3; loop++) {

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
                return col.HitPosition;
            }
        }
    }
    return VGet(0.0f, 0.0f, 0.0f);

}