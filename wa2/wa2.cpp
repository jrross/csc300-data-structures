#include <iostream>
#include "point.h"
#include "cube.h"
#include "sphere.h"
#include "shape3d.h"

using namespace std;

int main()
{
	point p(12, 6, 14);
	cube c(p, 15, 14, 13);
	sphere s(p, 13);
}

