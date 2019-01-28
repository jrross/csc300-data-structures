/***************************************************************************//**
 * @file cube.cpp
 ******************************************************************************/


#include "cube.h"

/***************************************************************************//**
 * @brief Constructor for a Cube object, Cubes are created in the positive x, y
	  , and z direction from the point provided.
 *
 * @param[in] p - the location of the object
 * @param[in] a - length of the object in the x-dimension
 * @param[in] b - length of the object in the y-dimension
 * @param[in] c - length of the object in the z-dimension
 ******************************************************************************/
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
	if(p.pointGet(1) > pc.pointGet(1) + x ||      //checks to see if the point is within the 
	   p.pointGet(1) < pc.pointGet(1))            //the lengths of the cube for each dimension.
		return false;
	if(p.pointGet(2) > pc.pointGet(2) + y ||
	   p.pointGet(2) < pc.pointGet(2))
		return false;
	if(p.pointGet(3) > pc.pointGet(3) + z ||
	   p.pointGet(3) < pc.pointGet(3))
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
