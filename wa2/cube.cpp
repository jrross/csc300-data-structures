#include "cube.h"

Cube::Cube (Point p, double a, double b, double c)
{
	pc.pointCopy(p);
	x = a;
	y = b;
	z = c;
	cout << "Created cube of dimensions " << x << "x" << y << "x" << z;
	cout << " at point " << pc.pointGet(1) << "," << pc.pointGet(2) << ",";
	cout << pc.pointGet(3) << endl;
}

bool Cube::contains(const Point &p) const
{
	if(p.pointGet(1) > pc.pointGet(1) + x)
		return false;
	if(p.pointGet(2) > pc.pointGet(2) + y)
		return false;
	if(p.pointGet(3) > pc.pointGet(3) + z)
		return false;
	return true;
}

double Cube::volume() const
{
	double temp;
	temp = x * y * z;
	return temp;
}

ostream& operator<<(ostream &out, Cube &c)
{
	out << c.pc.pointGet(1) << "," << c.pc.pointGet(2) << "," <<
	c.pc.pointGet(3) << " with dimensions: " << c.x << "x" <<
	c.y << "x" << c.z;
}
