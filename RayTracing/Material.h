#pragma once
#include "Color.h"

enum class Pattern {
	none,//模様なし 
	hstripe,//縞模様(横) 
	vstripe,//縞模様(縦) 
	checkered,//市松模様(チェッカーフラッグ) 
	textured//テクスチャマッピング 
};

class Material
{
public:
	Material();
	Material(const Color& diff, const Color& spec, const Color& amb, float inSpecularity, float inReflectance, Pattern pp = Pattern::none);
	~Material();

	Color diffuse;		//拡散反射成分(cosで表されるやつが返す色)
	Color specular;		//鏡面反射成分(スペキュラで決定される表面材質が返す色)
	Color ambient;		//環境光(ゲタ)
	float specularity;	//スペキュラの強さ(乗数)
	float reflectance;	//反射率
	Pattern pattern;//模様種別 
};

