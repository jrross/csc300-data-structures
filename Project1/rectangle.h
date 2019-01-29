/**************************************************************************//**
 * @file
 *****************************************************************************/

#include <iostream>
#include <GL/freeglut.h>
#include "shape.h"

#ifndef RECTANGLE_H
#define RECTANGLE_H

/*!
* @brief This is the Rectangle Class. It inherits from the Shape class.
*/
class Rectangle : public Shape
{
public:

  Rectangle(int i1, int j1, int i2, int j2, float c[3], 
                                           bool pal);/*!<rectangle constructor*/
  ~Rectangle();/*!<rectangle destructor*/
  void draw() const;/*!<rectangle draw function*/
  bool contains(int a, int b) const;/*!<rectangle contains function*/
  void isPallete();/*!<rectangle function to check if its in the palette*/
  void move(int x, int y);/*!<rectangle move function*/

private:
  float x1;/*!<x value for down click*/
  float y1;/*!<y value for down click*/
  float x2;/*!<x value for up click*/
  float y2;/*!<y value for up click*/
  bool p;


};

#endif
