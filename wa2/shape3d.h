#include "point.h"

#ifndef SHAPE3D_H
#define SHAPE3D_H
class shape3D
{
	public:
	
	virtual bool contains(const point &p) const = 0;
	virtual double volume() const = 0;
};



#endif

