#include <iostream>
#include "point.h"
#include "cube.h"
#include "sphere.h"
#include "shape3d.h"

using namespace std;

int main()
{
	point p(1, 1, 1);
	sphere s(p, 2);
	cube c(p, 1, 5, 3);

	point q(3 , 4.8, 2);
	if (s.contains(q))
		cout << "Things worked" << endl;
	cout << s.volume() << endl;
	if(c.contains(q))
		cout << "Things worked x2" << endl;
	cout << c.volume() << endl;


return 0;

}

