#include <dxlib.h>
#include <cmath>
#include <vector>
#include "Geometry.h"
#include "Plane.h"
#include "Sphere.h"
#include "Color.h"
#include "main.h"

using namespace std;

const int screen_width = 640;
const int screen_height = 480;

void FloorRender(const Position3& eye, Plane& plane, Vector3& ray, const Sphere& sphere, Vector3& light, float& distanse, int x, int y)
{
	float t = Dot(eye, plane.normal) - plane.offset / Dot(-ray, plane.normal);
	Vector3 intersectPos = eye + ray * t;
	if (Dot(plane.normal, ray) < 0)
	{
		Color col = plane.GetCheckColorFromPos(intersectPos);

		if (sphere.IsHitRay(intersectPos, -light, distanse))
		{
			col *= 0.5;
		}
		DrawPixel(x, y, col.GetColor());
	}
}

///レイトレーシング
///@param eye 視点座標
///@param sphere 球オブジェクト(そのうち複数にする)
void RayTracing(const Position3& eye,const Sphere& sphere, Plane& plane) {
	DrawBox(0, 0, screen_width, screen_height, GetColor(128, 128, 200), true);
	auto light = Vector3(-1, 1, 1);
	light.Normalize();
	for (int y = 0; y < screen_height; ++y) {//スクリーン縦方向
		for (int x = 0; x < screen_width; ++x) {//スクリーン横方向
			Position3 ScreenPos(x - screen_width / 2, -y + screen_height / 2, 0);
			Vector3 ray = ScreenPos - eye;
			ray.Normalize();
			float distanse = 0.0f;
			if(sphere.IsHitRay(eye,ray,distanse))
			{
				unsigned char b = 255;
				auto N = (ray * distanse - (sphere.pos - eye));
				N.Normalize();
				auto diffuse = Clamp(Dot(light, N));
				auto rlight = ReflectVector(light, N);
				float specular = pow(Clamp(Dot(rlight, ray)), 10.0f);

				Color diffCol(255, 0, 0);
				Color spcCol(255, 255, 255);
				Color ambCol(32, 32, 32);

				diffCol *= diffuse;
				spcCol *= specular;

				Color col = diffCol + spcCol;
				col = col.Max(ambCol);

				// 反射
				auto tmpRay = ReflectVector(ray, N);
				auto tmpStartPos = ray * distanse + eye;
				float t = Dot(tmpStartPos, plane.normal) - plane.offset / Dot(-tmpRay, plane.normal);
				Vector3 intersectPos = tmpStartPos + tmpRay * t;
				if (Dot(plane.normal, -tmpRay) > 0)
				{
					auto color = plane.GetCheckColorFromPos(intersectPos);
					auto r = Clamp(col.r * color.r / 255, 0, 255);
					auto g = Clamp(col.g * color.g / 255, 0, 255);
					auto b = Clamp(col.b * color.b / 255, 0, 255);

					DrawPixel(x, y, GetColor(r,g,b));
					continue;
				}

				DrawPixel(x, y, GetColor(col.r, col.g, col.b));
			}
			else
			{
				FloorRender(eye, plane, ray, sphere, light, distanse, x, y);
			}
		}
	}
}

void Move(Sphere& sphere)
{
	if (CheckHitKey(KEY_INPUT_W))
	{
		sphere.pos.y += 3;
	}
	if (CheckHitKey(KEY_INPUT_A))
	{
		sphere.pos.x -= 3;
	}
	if (CheckHitKey(KEY_INPUT_S))
	{
		sphere.pos.y -= 3;
	}
	if (CheckHitKey(KEY_INPUT_D))
	{
		sphere.pos.x += 3;
	}
}

int main() {
	ChangeWindowMode(true);
	SetGraphMode(screen_width, screen_height, 32);
	SetMainWindowText(_T("1816025_新田寛武"));
	DxLib_Init();

	vector<Primitive*> primitives;

	Sphere sphere(100, Position3(0, 0, -100));

	while(ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		ClsDrawScreen();

		Move(sphere);

		RayTracing(Vector3(0, 0, 300), sphere, Plane(Vector3(0, 1, 0), -100));

		ScreenFlip();
	}

	// WaitKey();
	DxLib_End();
}

