#include "Plane.h"



Plane::Plane()
{
}

Plane::Plane(const Vector3& inNormal, float inOffset) : normal(inNormal), offset(inOffset)
{
	normal.Normalize();
}

Plane::~Plane()
{
}

bool Plane::IsHitRay(const Position3 & startPos, const Vector3 & inray, float & distanse) const
{
	auto ray = inray;
	distanse = Dot(startPos, normal) - offset / Dot(-ray, normal);

	if (Dot(-ray, normal) < 0)
	{
		return true;
	}
}

Color Plane::GetCheckColorFromPos(Vector3 & intersectPos)
{
	bool flag = false;
	if (((int)intersectPos.x / 50 + (int)intersectPos.z / 50) % 2 == 0)
	{
		flag = true;
	}
	else
	{
		flag = false;
	}
	if (intersectPos.x <= 0)
	{
		flag = !flag;
	}
	if (intersectPos.z <= 0)
	{
		flag = !flag;
	}
	if (flag)
	{
		return Color(0, 0, 0);
	}
	else
	{
		return Color(255, 255, 255);
	}
}

const Material & Plane::GetMaterial() const
{
	return material;
}

float Plane::DistanceFromStart(const Position3 & pos)
{
	return 0.0f;
}
