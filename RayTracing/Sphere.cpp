#include "Sphere.h"



Sphere::Sphere() :radius(0), pos(0, 0, 0)
{
}

Sphere::Sphere(float r, Position3& p) : radius(r), pos(p)
{
}

Sphere::~Sphere()
{
}

bool Sphere::IsHitRay(const Position3 & startPos, const Vector3 & ray, float & distanse) const
{
	Vector3 C = pos - startPos;
	Vector3 R = ray * Dot(C, ray);
	Vector3 A = C - R;

	if (A.Magnitude() < radius)
	{
		float W = sqrt((radius * radius) - (A.Magnitude() * A.Magnitude()));
		distanse = R.Magnitude() - W;
		return true;
	}
	else
	{
		return false;
	}
}

const Material & Sphere::GetMaterial() const
{
	return material;
}

float Sphere::DistanceFromStart(const Position3 & pos)
{
	return 0.0f;
}
