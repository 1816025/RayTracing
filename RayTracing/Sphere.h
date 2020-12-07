#pragma once
#include "Primitive.h"
///球を表す構造体
class Sphere :
	public Primitive
{
public:
	Sphere();
	Sphere(float r, Position3& p);
	~Sphere();

	float radius;//半径
	Position3 pos; //中心座標

	bool IsHitRay(const Position3& startPos, const Vector3& ray, float& distanse) const;

	///マテリアルを返します 
	const Material& GetMaterial()const;

	///指定座標からの最短距離(球だったら中心との距離-半径。平面だったら垂線の長さ) 
	float DistanceFromStart(const Position3& pos);
};

