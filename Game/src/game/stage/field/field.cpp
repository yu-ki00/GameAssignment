#include"field.h"
using namespace std;
CField::CField() {
	Init();
}

CField::~CField() {
	Exit();
}

void CField::Init() {
    m_modelTable[1] = MV1LoadModel("Data/Model/field/floor.mv1");
    m_modelTable[2] = MV1LoadModel("Data/Model/field/floor.mv1");
    m_modelTable[3] = MV1LoadModel("Data/Model/field/floor.mv1");
}

void CField::Load() {
    ifstream file("Data/CSV/TilePath.csv");
    string line;

    int z = 0;

    while (getline(file, line)) {
        stringstream ss(line);
        string cell;

        int x = 0;

        while (getline(ss, cell, ',')) {
            int tile = stoi(cell);

            if (tile != 0) {
                STAGE_DATA data;

                data.m_tileID = tile;
                data.m_pos = VGet(x * TILE_SIZE, 0, z * TILE_SIZE);
                data.m_scale = VGet(1, 1, 1);
                data.m_rot = VGet(0, 0, 0);
                data.m_cellX = x;
                data.m_cellZ = z;

                // ★ここが重要
                data.m_hndl = MV1DuplicateModel(m_modelTable[tile]);

                data.m_isActive = true;

                m_stage.push_back(data);
            }

            x++;
        }
        z++;
    }
}

void CField::Step() {

}

void CField::Draw() {
    for (auto& data : m_stage) {
        if (!data.m_isActive) continue;

        // 座標
        MV1SetPosition(data.m_hndl, data.m_pos);

        // 回転
        MV1SetRotationXYZ(data.m_hndl, data.m_rot);

        // スケール
        MV1SetScale(data.m_hndl, data.m_scale);

        MV1DrawModel(data.m_hndl);
    }
}

void CField::Update() {
    for (auto& data : m_stage) {
        if (!data.m_isActive) continue;

    }
}

void CField::Exit() {
    // 配置モデル削除
    for (auto& data : m_stage) {
        MV1DeleteModel(data.m_hndl);
    }

    // 元モデル削除
    for (auto& m : m_modelTable) {
        MV1DeleteModel(m.second);
    }

    m_stage.clear();
    m_modelTable.clear();
}