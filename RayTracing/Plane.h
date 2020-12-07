#pragma once
#include "Primitive.h"
// ���ʂ�\���\����
class Plane :
	public Primitive
{
public:
	Plane();
	Plane(const Vector3& inNormal, float inOffset);
	~Plane();

	Vector3 normal;	// �@���x�N�g��(a,b,c)�����K�����Ƃ� 
	float offset;	// ���_����̃I�t�Z�b�g(d) 

	bool IsHitRay(const Position3& startPos, const Vector3& ray, float& distanse) const;

	Color GetCheckColorFromPos(Vector3& intersectPos);

	///�}�e���A����Ԃ��܂� 
	const Material& GetMaterial()const;

	///�w����W����̍ŒZ����(���������璆�S�Ƃ̋���-���a�B���ʂ������琂���̒���) 
	float DistanceFromStart(const Position3& pos);
};

