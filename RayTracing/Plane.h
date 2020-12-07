#pragma once
#include "Primitive.h"
// 平面を表す構造体
class Plane :
	public Primitive
{
public:
	Plane();
	Plane(const Vector3& inNormal, float inOffset);
	~Plane();

	Vector3 normal;	// 法線ベクトル(a,b,c)←正規化しとけ 
	float offset;	// 原点からのオフセット(d) 

	bool IsHitRay(const Position3& startPos, const Vector3& ray, float& distanse) const;

	Color GetCheckColorFromPos(Vector3& intersectPos);

	///マテリアルを返します 
	const Material& GetMaterial()const;

	///指定座標からの最短距離(球だったら中心との距離-半径。平面だったら垂線の長さ) 
	float DistanceFromStart(const Position3& pos);
};

