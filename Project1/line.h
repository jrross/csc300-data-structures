/**************************************************************************//**
 * @file
 *****************************************************************************/

#ifndef LINE_H
#define LINE_H

#include <GL/freeglut.h>
#include "shape.h"

/*!
* @brief This is the Line class. It inherits from the Shape class.
*/
class Line : public Shape
{
public:
  Line(int x1, int y1, int x2, int y2, float color[3]);/*!<line constructor*/
  ~Line();/*!<line destructor*/
  void draw() const;/*!<line draw function*/
  bool contains(int a, int b) const;/*!<line contains function*/
  void move(int x, int y);/*!<line move function*/
private:
  float x1;/*!<x value for down click*/
  float y1;/*!<y value for down click*/
  float x2;/*!<x value for up click*/
  float y2;/*!<y value for up click*/
};

#endif
