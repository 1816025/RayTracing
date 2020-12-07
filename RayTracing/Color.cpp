#include "Color.h"
#include "Geometry.h"




Color::Color() : r(0), g(0), b(0)
{
}

Color::Color(unsigned char inr, unsigned char ing, unsigned char inb) : r(inr), g(ing), b(inb)
{
}

Color::~Color()
{
}

void Color::operator*=(float scara)
{
	r = Clamp(r * scara, 0, 255);
	g = Clamp(g * scara, 0, 255);
	b = Clamp(b * scara, 0, 255);
}

void Color::operator+=(const Color & inVal)
{
	r = Clamp(r + inVal.r, 0, 255);
	g = Clamp(g + inVal.g, 0, 255);
	b = Clamp(b + inVal.b, 0, 255);
}

Color Color::operator+(const Color & inCol) const
{
	Color ret(r, g, b);
	ret.r = Clamp(ret.r + inCol.r, 0, 255);
	ret.g = Clamp(ret.g + inCol.g, 0, 255);
	ret.b = Clamp(ret.b + inCol.b, 0, 255);
	return ret;
}

Color Color::operator-(const Color & inCol) const
{
	Color ret(r, g, b);
	ret.r = Clamp(ret.r - inCol.r, 0, 255);
	ret.g = Clamp(ret.g - inCol.g, 0, 255);
	ret.b = Clamp(ret.b - inCol.b, 0, 255);
	return ret;
}

Color Color::operator*(const Color & inCol) const
{
	Color ret(r, g, b);
	ret.r = Clamp(ret.r * inCol.r, 0, 255);
	ret.g = Clamp(ret.g * inCol.g, 0, 255);
	ret.b = Clamp(ret.b * inCol.b, 0, 255);
	return ret;
}

Color Color::operator/(const int & inCol) const
{
	Color ret(r, g, b);
	ret.r = Clamp(ret.r / inCol, 0, 255);
	ret.g = Clamp(ret.g / inCol, 0, 255);
	ret.b = Clamp(ret.b / inCol, 0, 255);
	return ret;
}

Color Color::Max(const Color & col)
{
	Color ret(r, g, b);
	ret.r = max(col.r, ret.r);
	ret.g = max(col.g, ret.g);
	ret.b = max(col.b, ret.b);
	return ret;
}

unsigned int Color::GetColor() const
{
	return DxLib::GetColor(r, g, b);
}