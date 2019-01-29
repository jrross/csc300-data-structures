/**************************************************************************//**
 * @file
 *****************************************************************************/

#ifndef FILLEDRECTANGLE_H
#define FILLEDRECTANGLE_H
#include "rectangle.h"


/*!
* @brief This is the FilledRectangle Class. It inherits from the Rectangle class.
*/
class FilledRectangle : public Rectangle
{
public:

    FilledRectangle(int i1, int j1, int i2, int j2, float c[3], float b[3]);/*!<filled rectangle constructor*/
    ~FilledRectangle();/*!<filled rectangle destructor*/
    void draw() const;/*!<filled rectangle draw function*/
    bool contains(int a, int b) const;/*!<filled rectangle contains function*/
    void move(int x, int y);/*!<filled rectangle move function*/

private:
    float x1;/*!<x value for down click*/
    float y1;/*!<y value for down click*/
    float x2;/*!<x value for up click*/
    float y2;/*!<y value for up click*/
};

#endif
