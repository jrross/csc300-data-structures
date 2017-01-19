#include <iostream>

using namespace std;

class point
{

	public: 

	point(double a, double b, double c);
	void print();

	private:

	double x;
	double y;
	double z;
};

point::point(double a, double b, double c)
{
	x = a;
	y = b;
	z = c;
}



void point::print()
{
	cout << x << " " << y << " " << z << endl;
}
