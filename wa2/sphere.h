#include "point.h"
#include "shape3d.h"

#ifndef SPHERE_H
#define SPHERE_H
class sphere : public shape3D
{
	public:

	sphere (point, double);
	bool contains(const point &p) const = 0;

	private:

	double radius;
	point ps;
};

sphere::sphere(point p, double r)
{
	ps.pointCopy(p);
	radius = r;
	cout << "Created sphere of radius " << radius << " at point ";
	cout << ps.pointGet(1) << "," << ps.pointGet(2) << ",";
	cout << ps.pointGet(3) << endl;
}

	bool sphere::contains(const point &p) const = 0
{
	if (p.pointGet(1) > ps.pointGet(1) + radius ||
	    p.pointGet(1) < ps.pointGet(1) - radius )
		return false;

	if (p.pointGet(2) > ps.pointGet(2) + radius ||
	    p.pointGet(2) < ps.pointGet(2) - radius )
		return false;

	if (p.pointGet(3) > ps.pointGet(3) + radius ||
	    p.pointGet(3) < ps.pointGet(3) - radius )
		return false;
	return true;
}
#endif
