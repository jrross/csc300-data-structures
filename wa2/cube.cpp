#include "cube.h"

cube::cube (point p, double a, double b, double c)
{
	pc.pointCopy(p);
	x = a;
	y = b;
	z = c;
	cout << "Created cube of dimensions " << x << "x" << y << "x" << z;
	cout << " at point " << pc.pointGet(1) << "," << pc.pointGet(2) << ",";
	cout << pc.pointGet(3) << endl;
}

bool cube::contains(const point &p) const
{
	if(p.pointGet(1) > pc.pointGet(1) + x)
		return false;
	if(p.pointGet(2) > pc.pointGet(2) + y)
		return false;
	if(p.pointGet(3) > pc.pointGet(3) + z)
		return false;
	return true;
}

double cube::volume() const
{
	double temp;
	temp = x * y * z;
	return temp;
}
