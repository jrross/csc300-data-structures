#include "point.h"

#ifndef CUBE_H
#define CUBE_H
class cube
{
	public:
	
	cube (point);

	private:
	
	double sideSize;
	double x;
	double y;
	double z;

};

cube::cube (point p)
{
	sideSize = 5.0;
	x = p.pointGet(1);
	y = p.pointGet(2);
	z = p.pointGet(3);
}
#endif
