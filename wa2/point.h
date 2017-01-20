#include <iostream>

using namespace std;

#ifndef POINT_H
#define POINT_H 
class point
{
	public: 

	point(double a = 0, double b = 0, double c = 0);
	double pointGet(int g) const;
	void pointCopy(point a);

	private:

	double x;
	double y;
	double z;
};
#endif


