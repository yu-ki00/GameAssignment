#pragma once
#include<DxLib.h>

float GetDistance(float PosX, float PosY, float posx, float posy);
VECTOR AddVector(VECTOR A, VECTOR B);
VECTOR SubVector(VECTOR A, VECTOR B);

//ベクトルの生成
VECTOR CreateVec(VECTOR endPos, VECTOR startPos);

//ベクトルの長さを取得
float GetVecLength(VECTOR vec);

//ベクトルを正規化
VECTOR VecNorm(VECTOR vec, float length);

//ベクトルのスカラー倍
VECTOR VecScale(VECTOR vec,float scale);

//内積
float VecDot(VECTOR vec1, VECTOR vec2);

//単位行列を取得する
MATRIX GetIdentityMatrix();

//平行移動行列を取得する
MATRIX GetTranslateMatrix(VECTOR trans);


MATRIX GetTranslateVecMatrix(float x, float y, float z);

//拡縮行列を取得する
MATRIX GetScaleMatrix(VECTOR scale);

//X軸回転行列を取得する
MATRIX GetPitchMatrix(float radx);

//Y軸回転行列を取得する
MATRIX GetYawMatrix(float rady);

//Z軸回転行列を取得する
MATRIX GetRollMatrix(float radz);

//引数で渡された２つの行列を足し算する
MATRIX MatAdd(MATRIX Mat1,MATRIX Mat2);

//引数で渡された行列をスカラー倍する
MATRIX MatScale(MATRIX Mat, float scal);

//引数で渡された２つの行列の掛け算を行う
MATRIX MatMult(MATRIX Mat1, MATRIX Mat2);

//行列×ベクトルを行う（変換計算）
VECTOR MatTransform(MATRIX Mat, VECTOR vec);

//行列転置を行う
MATRIX MatTranspose(MATRIX Mat);

float DegRad(float deg);

inline float clamp(float v, float minV, float maxV);