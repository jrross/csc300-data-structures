#include "point.h"

#ifndef SHAPE3D_H
#define SHAPE3D_H
class shape3D
{
	point location;

	public:
	
	shape3D();
	virtual bool contains(const point &) const = 0;
	virtual double volume() const = 0;
};



#endif

