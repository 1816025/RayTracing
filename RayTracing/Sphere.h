#pragma once
#include "Primitive.h"
///����\���\����
class Sphere :
	public Primitive
{
public:
	Sphere();
	Sphere(float r, Position3& p);
	~Sphere();

	float radius;//���a
	Position3 pos; //���S���W

	bool IsHitRay(const Position3& startPos, const Vector3& ray, float& distanse) const;

	///�}�e���A����Ԃ��܂� 
	const Material& GetMaterial()const;

	///�w����W����̍ŒZ����(���������璆�S�Ƃ̋���-���a�B���ʂ������琂���̒���) 
	float DistanceFromStart(const Position3& pos);
};

