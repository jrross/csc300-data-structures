#include <iostream>
#include <vector>
#include "point.h"
#include "shape3d.h"
#include "sphere.h"
#include "cube.h"

using namespace std;

int main()
{
   Point p(1, 1, 1);          /// Create a Point at coordinate [1,1,1]
   Sphere sphere(p);          /// Create a Sphere at point p
   Cube cube(p);              /// Create a Cube at point p

   Point q(1.1, 1.1, 1.1);    /// Create a Point at coordinate [1.1,1.1,1.1]

   if (sphere.contains(q))
      cout << "Sphere at " << sphere << " contains point at " << q << "\n";

   if (cube.contains(q))
      cout << "Cube at " << cube << " contains point at " << q << "\n";


   cout << "Volume of shape = " << sphere.volume() << endl;
   cout << "Volume of shape = " << cube.volume() << endl;
   return 0;
}
