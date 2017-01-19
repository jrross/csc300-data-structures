#include <iostream>

using namespace std;

#ifndef POINT_H
#define POINT_H 
class point
{
	public: 

	point(double, double, double);
	double pointGet(int g);

	private:

	double x;
	double y;
	double z;
};

point::point(double a = 0, double b = 0, double c = 0)
{
	x = a;
	y = b;
	z = c;
}

double point::pointGet(int g)
{
	if(g == 1)
		return x;
	if(g == 2)
		return y;
	if(g == 3)
		return z;
	else
		return 0;
}
#endif

