#include "point.h"

#ifndef CUBE_H
#define CUBE_H
class cube
{
	public:
	
	cube (point, double = 1.0, double = 1.0, double = 1.0);
	bool contains(const point &p) const;
	double volume() const;

	private:
	
	point pc;
	double x;
	double y;
	double z;

};

#endif
