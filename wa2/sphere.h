#include "point.h"
#include "shape3d.h"

#ifndef SPHERE_H
#define SPHERE_H
class sphere : public shape3D
{
	public:

	sphere (point, double r = 1.0);
	bool contains(const point &p) const;
	double volume() const;

	private:

	double radius;
	point ps;
};
#endif
