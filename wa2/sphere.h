#include "point.h"

#ifndef SPHERE_H
#define SPHERE_H
class sphere
{
	public:

	sphere (point);

	private:

	double radius;
	double x;
	double y;
	double z;

};

sphere::sphere(point p)
{
	radius = 5.0;
	x = p.pointGet(1);
	y = p.pointGet(2);
	z = p.pointGet(3);
}
#endif
