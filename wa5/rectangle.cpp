#include "rectangle.h"

void rectangle::setCenter(float x, float y)
{
	xCenter = x;
	yCenter = y;
	x1 = xCenter - 100;
	y1 = yCenter - 100;
	x2 = xCenter + 100;
	y2 = yCenter + 100;
}
float rectangle::getx1()
{
	return x1;
}
float rectangle::getx2()
{
	return x2;
}
float rectangle::gety1()
{
	return y1;
}
float rectangle::gety2()
{
	return y2;
}
