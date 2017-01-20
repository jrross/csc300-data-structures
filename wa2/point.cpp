#include "point.h"

point::point(double a, double b, double c)
{
	x = a;
	y = b;
	z = c;
}

void  point::pointCopy(point a)
{
	x = a.pointGet(1);
	y = a.pointGet(2);
	z = a.pointGet(3);
}

double point::pointGet(int g) const
{
	if(g == 1)
		return x;
	if(g == 2)
		return y;
	if(g == 3)
		return z;
	else
		return 0;
}
