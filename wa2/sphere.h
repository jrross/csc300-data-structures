#include "point.h"
#include "shape3d.h"

#ifndef SPHERE_H
#define SPHERE_H
class Sphere : public shape3D
{
	public:

	Sphere (Point, double r = 1.0);
	bool contains(const Point &p) const;
	double volume() const;
	friend ostream& operator<<(ostream &out, Sphere &s);

	private:

	double radius;
	Point ps;
};
#endif
