#pragma once
#include "Geometry.h"
#include <DxLib.h>
#include <cmath>
#include "Material.h"
// �􉽊w�͗l�̂��߂̊��N���X
class Primitive
{
public:
	Primitive() {}
	Primitive(const Material& m) : material(m) {}
	virtual ~Primitive() {}

protected:
	// ڲ�Ǝ����̌���������s��
	///@param startPos �n�_
	///@param ray ڲ�޸��(���K����)
	///@param distanse�y�o�͗p�z��_�܂ł̋���
	virtual bool IsHitRay(const Position3& startPos, const Vector3& ray, float& distanse) const = 0;

	///�}�e���A����Ԃ��܂� 
	 ///@return �}�e���A���I�u�W�F�N�g 
	virtual const Material& GetMaterial()const = 0;

	///�w����W����̍ŒZ����(���������璆�S�Ƃ̋���-���a�B���ʂ������琂���̒���) 
	///@param p �����𑪂肽���_(���W) 
	virtual float DistanceFromStart(const Position3& pos) = 0;

	Material material;
};

