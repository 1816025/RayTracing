#pragma once
#include <DxLib.h>
class Color
{
public:
	Color();
	Color(unsigned char inr, unsigned char ing, unsigned char inb);
	~Color();

	void operator *= (float scara);
	void operator += (const Color& inVal);

	Color operator + (const Color& inCol) const;
	Color operator - (const Color& inCol) const;
	Color operator * (const Color& inCol) const;
	Color operator / (const int& inCol) const;
	Color Max(const Color& col);

	unsigned int GetColor()const;

	unsigned char r, g, b;
};

