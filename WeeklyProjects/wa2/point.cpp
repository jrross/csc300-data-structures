#include "point.h"

Point::Point(double a, double b, double c)
{
	x = a;
	y = b;
	z = c;
}

void  Point::pointCopy(Point a)
{
	x = a.pointGet(1); //does a straight copy from provided point using pointGet
	y = a.pointGet(2);
	z = a.pointGet(3);
}

double Point::pointGet(int g) const
{
	if(g == 1)        //takes 1, 2, or 3 for corresponding xyz value
		return x;
	if(g == 2)
		return y;
	if(g == 3)
		return z;
	else
		return 0;
}

ostream& operator<<(ostream &out, Point &p)
{
	out << p.x << "," << p.y << "," << p.z;
}
