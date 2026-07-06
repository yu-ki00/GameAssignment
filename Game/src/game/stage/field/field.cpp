#include"field.h"
#include"../../common.h"
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
    for (auto& data : m_stage) {
        if (data.m_tileID == 2) {
            PATH_DATA pathData;
            pathData.spawnPos = data.m_pos;

            pathData.path = CreatePath(data);
            m_enemyPaths.push_back(pathData);
        }
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

//エネミー出現位置
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

//クリスタル出現位置
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

vector<VECTOR> CField::CreatePath(const STAGE_DATA& start)
{
    //完成した経路を入れる配列
    vector<VECTOR> path;
    //BFSで使用する座標
    struct NODE {
        int x;
        int z;
    };
    //探索待ちのマスを入れるキュー
    queue<NODE> q;

    //ゴールからスタートまで経路を逆にたどるためにマスの親子関係を保存
    map<pair<int, int>, pair<int, int>> parent;

    //探索済みのマスを入れる
    set<pair<int, int>> visited;

    //スタート座標
    int sx = start.m_cellX;
    int sz = start.m_cellZ;

    //スタートを探索開始
    q.push({ sx,sz });

    //スタートを探索済みにする
    visited.insert({ sx,sz });

    //ゴール座標を入れる
    int goalX = -1;
    int goalZ = -1;

    //上下左右
    int dx[4] = { 1,-1,0,0 };
    int dz[4] = { 0,0,1,-1 };

    //キューが空になるまで探索
    while (!q.empty())
    {
        //一番先頭のマスを取り出す
        NODE now = q.front();

        q.pop();

        //現在のマス取得
        STAGE_DATA* tile = GetTile(now.x, now.z);

        //ゴールなら探索終了
        if (tile && tile->m_tileID == 3){
            goalX = now.x;
            goalZ = now.z;
            break;
        }

        //四方向を調べる
        for (int i = 0;i < 4;i++) {

            int nx = now.x + dx[i];
            int nz = now.z + dz[i];

            //すでに探索済みなら次へ
            if (visited.count({ nx,nz }))
                continue;

            //隣のマス取得
            STAGE_DATA* next = GetTile(nx, nz);

            //マスが存在しないなら次へ
            if (!next)
                continue;

            //道またはゴールなら進める
            if (next->m_tileID == 5 || next->m_tileID == 3) {
                //探索済みにする
                visited.insert({ nx,nz });

                //このマスへ来る前のマスを保存する
                parent[{nx, nz}] = { now.x,now.z };

                //次に進む
                q.push({ nx,nz });
            }
        }

    }

    //ゴールが見つからなかったらCSVの問題だから終了
    if (goalX == -1)
        return path;
    //ゴールからスタートまで逆順で保存
    vector<pair<int, int>> reversePath;

    int x = goalX;
    int z = goalZ;

    //ゴールを追加
    reversePath.push_back({ x,z });

    //スタートまで親をたどる
    while(!(x == sx && z == sz))
    {

        auto p = parent[{x, z}];
        x = p.first;
        z = p.second;

        reversePath.push_back({ x,z });
    }
    //まだ逆だからスタートから並び変える
    for (int i = (int)reversePath.size() - 1;i >= 0;i--) {
        auto p = reversePath[i];

        STAGE_DATA* tile = GetTile(p.first, p.second);
        if (tile) {
            //座標を経路に追加
            path.push_back(tile->m_pos);
        }
    }
    //完成した経路を返す
    return path;
}
