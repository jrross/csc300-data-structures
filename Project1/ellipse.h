/**************************************************************************//**
 * @file
 *****************************************************************************/

#ifndef _ELLIPSE_H__
#define _ELLIPSE_H__

#include <GL/freeglut.h>
#include "shape.h"

/*!
* @brief This is the Ellipse Class. It inherits from the Shape class.
*/

class Ellipse : public Shape
{
public:
    Ellipse(int inX1, int inY1, int inX2, int inY2, 
                                     float inColor[3]);/*!<ellipse constructor*/
    ~Ellipse();/*!<ellipse destructor*/
    void draw() const;/*!<ellipse draw function*/
    bool contains(int a, int b) const;/*!<ellipse contains function*/
    void move(int x, int y);/*!<ellipse move function*/
private:
    float x1;/*!<x value for down click*/
    float y1;/*!<y value for down click*/
    float x2;/*!<x value for up click*/
    float y2;/*!<y value for up click*/
};

#endif
