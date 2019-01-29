/**************************************************************************//**
 * @file
 *****************************************************************************/

#ifndef FILLEDELLIPSE_H
#define FILLEDELLIPSE_H
#include "ellipse.h"


/*!
* @brief This is the FilledEllipse Class. It inherits from the Ellipse class.
*/
class FilledEllipse : public Ellipse
{
public:
    FilledEllipse(int inX1, int inY1, int inX2, int inY2, float c[3], 
                                     float b[3]);/*!<FilledEllipse constructor*/
    ~FilledEllipse();/*!<filled ellipse destructor*/
    void draw() const;/*!<filled ellipse draw function*/
    bool contains(int a, int b) const;/*!<filled ellipse contains function*/
    void move(int x, int y);/*!<filled ellipse move function*/
private:
    float x1;/*!<x value for down click*/
    float y1;/*!<y value for down click*/
    float x2;/*!<x value for up click*/
    float y2;/*!<y value for up click*/
};

#endif
