#include "point.h"

#ifndef CUBE_H
#define CUBE_H
class Cube
{
	public:
	
	Cube (Point, double = 1.0, double = 1.0, double = 1.0);
	bool contains(const Point &p) const;
	double volume() const;
	friend ostream& operator<<(ostream &out, Cube &c);	

	private:
	
	Point pc;  //starting point for the cube
	double x;
	double y;
	double z;

};

#endif
