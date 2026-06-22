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
    m_modelTable[2] = MV1LoadModel("Data/Model/field/magicfloor.mv1");
    m_modelTable[3] = MV1LoadModel("Data/Model/field/floor.mv1");
    m_modelTable[4] = MV1LoadModel("Data/Model/field/wall.mv1");
    m_modelTable[5] = MV1LoadModel("Data/Model/field/road.mv1");
}

void CField::Load() {
    ifstream file("Data/CSV/StagePath.csv");
    string line;

    int z = 0;
    vector<VECTOR>m_pathList;

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

                data.m_hndl = MV1DuplicateModel(m_modelTable[tile]);

                data.m_isActive = true;


                m_stage.push_back(data);
            }

            x++;
        }
        z++;
    }
    CreatePath();

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

VECTOR CField::GetSpawnPos() {
    vector<VECTOR> spawnPos;
    for (auto& data : m_stage) {
        if (data.m_tileID == 2) {
            spawnPos.push_back(data.m_pos);
        }
    }
    int index=GetRand(spawnPos.size() - 1);
    return spawnPos[index];
}

VECTOR CField::GetStartPos() {
    for (auto& data : m_stage) {

        if (data.m_tileID == 3) {
            return data.m_pos;
        }
    }
}

CField::STAGE_DATA* CField::GetTile(int x, int z) {
    for (auto& data : m_stage) {
        if (data.m_cellX == x && data.m_cellZ == z) {
            return &data;
        }
    }
    return nullptr;
}

void CField::CreatePath() {
    m_enemyPath.clear();

    STAGE_DATA* start = nullptr;
    for (auto& data : m_stage) {
        
        if (data.m_tileID == 2) {
            start = &data;
            break;
        }
    }
    if (!start)return;
    int x = start->m_cellX;
    int z = start->m_cellZ;

    m_enemyPath.push_back(start->m_pos);

    vector<pair<int, int>> visited;

    visited.push_back({ x,z });

    while (true) {
        bool found = false;

        int dx[4] = { 1,-1,0,0 };

        int dz[4] = { 0,0,1,-1 };

        for (int i = 0;i < 4;i++) {
            int nx = x + dx[i];

            int nz = z + dz[i];

            bool already = false;

            for (auto& v : visited) {
                if (v.first == nx && v.second == nz) {
                    already = true;
                    break;
                }
            }

            if (already)
                continue;

            STAGE_DATA* tile = GetTile(nx, nz);

            if (!tile)
                continue;

            if (tile->m_tileID == 5 || tile->m_tileID == 3) {
                m_enemyPath.push_back(tile->m_pos);

                visited.push_back({ nx,nz });

                x = nx;

                z = nz;

                found = true;
                if (tile->m_tileID == 3) {
                    return;
                }
                break;
            }
        }
        if (!found)
            return;
    }

}