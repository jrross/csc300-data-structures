#include <iostream>

using namespace std;

#ifndef POINT_H
#define POINT_H 
class Point
{
	public: 

	Point(double a = 0, double b = 0, double c = 0);
	double pointGet(int g) const;
	void pointCopy(Point a);
	friend ostream& operator<<(ostream &out, Point &p);

	private:

	double x;
	double y;
	double z;
};
#endif


