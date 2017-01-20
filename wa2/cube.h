#include "point.h"

#ifndef CUBE_H
#define CUBE_H
class cube
{
	public:
	
	cube (point, double, double, double);

	private:
	
	point pc;
	double x;
	double y;
	double z;

};

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
#endif
