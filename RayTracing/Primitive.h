#pragma once
#include "Geometry.h"
#include <DxLib.h>
#include <cmath>
#include "Material.h"
// 幾何学模様のための基底クラス
class Primitive
{
public:
	Primitive() {}
	Primitive(const Material& m) : material(m) {}
	virtual ~Primitive() {}

protected:
	// ﾚｲと自分の交差判定を行う
	///@param startPos 始点
	///@param ray ﾚｲﾍﾞｸﾄﾙ(正規化済)
	///@param distanse【出力用】交点までの距離
	virtual bool IsHitRay(const Position3& startPos, const Vector3& ray, float& distanse) const = 0;

	///マテリアルを返します 
	 ///@return マテリアルオブジェクト 
	virtual const Material& GetMaterial()const = 0;

	///指定座標からの最短距離(球だったら中心との距離-半径。平面だったら垂線の長さ) 
	///@param p 距離を測りたい点(座標) 
	virtual float DistanceFromStart(const Position3& pos) = 0;

	Material material;
};

