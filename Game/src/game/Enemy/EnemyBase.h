#pragma once
#include"../common.h"
#include"../../lib/Object/Object3D.h"
#include <vector>
using namespace std;
class CEnemyBase:public CObject3D {
private:
	float m_hp;

	float m_speed;

	bool m_slow;

	int m_fireTime;

	int m_damageTime;

	bool m_isKnock;

	VECTOR m_knockPow;

	int m_knockTime;

	bool m_isDamage;

	bool m_isFire;

	bool m_isDeath;

	int m_pathIndex;

	vector<VECTOR> m_path;
public:
	CEnemyBase();
	~CEnemyBase();
	virtual void Init();
	virtual void Load(int originHndl);
	virtual void Step();
	virtual void Draw();
	virtual void Exit();

	virtual void SubHp(int sub) { m_hp -= sub; }

	virtual void SetSlow(bool slow) { m_slow = slow; }

	virtual bool GetSlow() { return m_slow; }

	virtual void HitDamage();

	virtual void SetFire();

	virtual void KnockBack(VECTOR vec);

	virtual bool GetIsDamage() { return m_isDamage; }

	virtual bool GetIsDeath() { return m_isDeath; }

	virtual void SetPath(const vector<VECTOR>& path);
};