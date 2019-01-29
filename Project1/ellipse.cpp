/**************************************************************************//**
 * @file
 *****************************************************************************/

#include "ellipse.h"
#include <cmath>
#define _USE_MATH_DEFINES

/***************************************************************************//** 
* @author Luke Videckis
*
* @par Description:
* This is the constructor for the Ellipse class. It just updates the values for 
* the class. (no way!)
*
* @param[in] inX1 - the x value of the down click
* @param[in] inY1 - the y value of the down click
* @param[in] inX2 - the x value of the up click
* @param[in] inY2 - the y value of the up click
* @param[in] inColor - the float of RGB values for the Ellipse 
*
* @returns nothing
*
******************************************************************************/
Ellipse::Ellipse(int inX1, int inY1, int inX2, int inY2, float inColor[3])
{
    x1 = inX1;
    y1 = inY1;
    x2 = inX2;
    y2 = inY2;
    for(int i = 0; i < 3; i++) {
        this->color[i] = inColor[i];
    }
}

/***************************************************************************//**
* @author Luke Videckis
*
* @par Description:
* This is the destructor for the Ellipse class. It also does absolutely nothing. 
*
* @returns nothing
*
******************************************************************************/
Ellipse::~Ellipse(){}

/*********************************************************************//**
* @author Luke Videckis
*
* @par Description:
* This function draws an ellipse
*
* @returns nothing
*
************************************************************************/
void Ellipse::draw() const
{
    float centerX, centerY, radiusX, radiusY, Rad = M_PI / 180.0;
    centerX = (this->x1 + this->x2) / 2.0;
    centerY = (this->y1 + this->y2) / 2.0;
    radiusX = centerX - this->x1;
    radiusY = centerY - this->y1;
    if(radiusX < 0)//weird error with cmath abs function, using this instead
        radiusX = -1 * radiusX;
    if(radiusY < 0)
        radiusY = -1 * radiusY;
    glBegin(GL_LINE_LOOP);
    glColor3fv(this->color);
    for(int i = 0; i < 360; i++)
    {
        float rad = i*Rad;
        glVertex2f(centerX + cos(rad)*radiusX, centerY + sin(rad)*radiusY);
    }
    glEnd();
}

/*********************************************************************//**
* @author Luke Videckis
*
* @par Description:
* This functions returns true if the click is inside the ellipse and false
* otherwise.
*
* @param a - the x value of the click to be checked
* @param b - the y value of the click to be checked
*
* @returns true if the click is inside the ellipse
* @returns false if the click is outside the ellipse
*
************************************************************************/
bool Ellipse::contains(int a, int b) const
{
    float centerX, centerY, radiusX, radiusY;
    centerX = (this->x1 + this->x2) / 2.0;
    centerY = (this->y1 + this->y2) / 2.0;
    radiusX = centerX - this->x1;
    radiusY = centerY - this->y1;
    float xDiff = (a - centerX) * (a - centerX) / (float) (radiusX * radiusX);
    float yDiff = (b - centerY) * (b - centerY) / (float) (radiusY * radiusY);
    return xDiff + yDiff <= 1;
}
/*********************************************************************//**
* @author Jeffrey Ross
*
* @par Description:
* this function displaces the object on the xy axis' with the provided
* x and y value
*
* param[in] x - amount to displace on x axis
* param[in] y - amount to displace on y axis
*
* @returns nothing
*
************************************************************************/
void Ellipse::move(int x, int y)
{
	x1 = x1 + x;
	x2 = x2 + x;
	y1 = y1 + y;
	y2 = y2 + y;
}
