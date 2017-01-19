#include <iostream>
#include "point.h"
#include "cube.h"
#include "sphere.h"

using namespace std;

int main()
{
	point p(1, 1, 1);
	cube c(p);
	sphere s(p);
	point q(1.1, 1.1, 1.1);
	if(c.cointains(q))
	cout << "true" << endl;
}

