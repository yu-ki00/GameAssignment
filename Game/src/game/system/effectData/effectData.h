#pragma once


enum tagEffectKind	//エフェクトの種類
{
	EFFECT_GATE,		//コイン獲得エフェクト
	EFFECT_FIRE,		//炎エフェクト

	EFFECT_NUM,				//エフェクトの数
};

class CEffectData
{
private:
	static int m_id[EFFECT_NUM];			//エフェクトのID
public:
	//コンストラクタ
	CEffectData();

	//初期化
	static void Init();

	//ロード
	static void Load();

	//エフェクトのIDを取得
	static int GetId(tagEffectKind _kind) { return m_id[_kind]; }

};

