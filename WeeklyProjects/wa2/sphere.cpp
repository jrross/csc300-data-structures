/***************************************************************************//**
 * @file sphere.cpp
 ******************************************************************************/

#include "sphere.h"


/***************************************************************************//**
 * @brief Constructor for a Sphere object, the point provided will be the center
	  of the sphere.
 *
 * @param[in] p - the location of the object
 * @param[in] a - length of the object in the x-dimension
 * @param[in] b - length of the object in the y-dimension
 * @param[in] c - length of the object in the z-dimension
 ******************************************************************************/
Sphere::Sphere(Point p, double r)
{
	ps.pointCopy(p);
	radius = r;
	cout << "Created sphere of radius " << radius << " at point ";
	cout << ps.pointGet(1) << "," << ps.pointGet(2) << ",";
	cout << ps.pointGet(3) << endl;
}

bool Sphere::contains(const Point &p) const
{
	if (p.pointGet(1) > ps.pointGet(1) + radius ||    //checks to see if the point is within the
	    p.pointGet(1) < ps.pointGet(1) - radius )     //length of the radius from the center in
		return false;                             //the + and - coordinate direction.

	if (p.pointGet(2) > ps.pointGet(2) + radius ||
	    p.pointGet(2) < ps.pointGet(2) - radius )
		return false;

	if (p.pointGet(3) > ps.pointGet(3) + radius ||
	    p.pointGet(3) < ps.pointGet(3) - radius )
		return false;
	return true;
}

double Sphere::volume() const
{
	double temp;
	temp = (4.0 / 3.0) * 3.14159 * (radius * radius * radius);
	return temp;
}

ostream& operator<<(ostream &out, Sphere &s)
{
	out << s.ps.pointGet(1) << "," << s.ps.pointGet(2) << "," <<
	s.ps.pointGet(3) << " with a radius of: " << s.radius;
}
