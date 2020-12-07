#pragma once

void Move(Sphere& sphere);

void FloorRender(const Position3& eye, Plane& plane, Vector3& ray, const Sphere& sphere, Vector3& light, float& distanse, int x, int y);
