#pragma once
#include"../../../lib/Object/Object3D.h"
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <queue>
#include <map>
#include <set>

static const float TILE_SIZE = 200.0f;
using namespace std;
static const char FIELD_PATH[] = { "Data/Model/field/field.mv1" };

static const int TILE_NUM = 5;

struct PATH_DATA
{
	VECTOR spawnPos;
	vector<VECTOR> path;
};

struct NODE
{
	int x;
	int z;
};
class CField {
private:
	typedef struct {
		VECTOR m_pos;		//座標

		VECTOR m_scale;		//モデルサイズ

		VECTOR m_rot;		//モデル角度

		int m_hndl;			//モデルハンドル

		bool m_isActive;	//生存判定

		int m_tileID;		//タイルの識別

		int m_cellX;

		int m_cellZ;
	}STAGE_DATA;


	map<int, int> m_modelTable;

	vector<VECTOR> m_enemyPath;

	vector<STAGE_DATA> m_stage;

	vector<vector<int>> m_map;

	VECTOR m_startPos;

	vector<vector<VECTOR>> m_path;

	vector<PATH_DATA> m_enemyPaths;
public:
	CField();

	~CField();

	void Init();

	void Load();

	void Step();

	void Draw();

	void Update();

	void Exit();

	vector<VECTOR> CreatePath(const STAGE_DATA& start);

	const vector<VECTOR>& GetPath() const
	{
		return m_enemyPath;
	}

	STAGE_DATA* GetTile(int x, int z);

	const vector<STAGE_DATA>& GetStage() const {
		return m_stage;
	}

	VECTOR GetSpawnPos();

	VECTOR GetStartPos();

	int GetPathNum() const { return (int)m_enemyPaths.size(); }
	const PATH_DATA& GetPathData(int index) const { return m_enemyPaths[index]; }

};