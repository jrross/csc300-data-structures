/**************************************************************************//**
 * @file
 *****************************************************************************/

#include "FilledEllipse.h"
#include <cmath>
#define _USE_MATH_DEFINES

/***************************************************************************//**
* @author Luke Videckis
*
* @par Description:
* This is the constructor for the FilledEllipse class. It just updates the 
* values for the class.
*
* @param[in] inX1 - the x value of the down click
* @param[in] inY1 - the y value of the down click
* @param[in] inX2 - the x value of the up click
* @param[in] inY2 - the y value of the up click
* @param[in] c - the float of RGB values for the color of the Ellipse 
* @param[in] b - the float of RGB values for the border of the Ellipse 
*
* @returns nothing
*
******************************************************************************/
FilledEllipse::FilledEllipse(int inX1, int inY1, int inX2, int inY2, float c[3], 
                             float b[3]) : Ellipse(inX1, inY1, inX2, inY2, c)
{
    x1 = inX1;
    y1 = inY1;
    x2 = inX2;
    y2 = inY2;
    for(int i = 0; i < 3; i++) {
        color[i] = c[i];
        border[i] = b[i];
    }
}

/***************************************************************************//**
* @author Luke Videckis
*
* @par Description:
* This is the destructor for the FilledEllipse class. It doesn't do much.
*
* @returns nothing
*
******************************************************************************/
FilledEllipse::~FilledEllipse(){}

/*********************************************************************//**
* @author Luke Videckis
*
* @par Description:
* This function draws an ellipse with a fill and border color.
*
* @returns nothing
*
************************************************************************/
void FilledEllipse::draw() const
{
    float centerX, centerY, radiusX, radiusY, Rad = M_PI / 180.0;
    centerX = (this->x1 + this->x2) / 2.0;
    centerY = (this->y1 + this->y2) / 2.0;
    radiusX = centerX - this->x1;
    radiusY = centerY - this->y1;
    if(radiusX < 0)
        radiusX = -1 * radiusX;
    if(radiusY < 0)
        radiusY = -1 * radiusY;
    glBegin(GL_POLYGON);
    glColor3fv(this->color);
    for(int i = 0; i < 360; i++)
    {
        float rad = i*Rad;
        glVertex2f(centerX + cos(rad)*radiusX, centerY + sin(rad)*radiusY);
    }
    glEnd();
    float tempColor[3];
    for(int i = 0; i < 3; i++)
        tempColor[i] = border[i];
    Ellipse temp(x1, y1, x2, y2, tempColor);
    temp.draw();
    
}

/*********************************************************************//**
* @author Luke Videckis
*
* @par Description:
* This functions returns true if the click is inside the ellipse and false
* otherwise. It is exactly the same as the contains function for the ellipse
* class.
*
* @param a - the x value of the click to be checked
* @param b - the y value of the click to be checked
*
* @returns true if the click inside the ellipse
* @returns false if the click is outside the ellipse
*
************************************************************************/
bool FilledEllipse::contains(int a, int b) const
{
    //used equation (x-x1)^2/xradius^2 + (y-y1)^2/yradius^2 = 1 for an ellipse
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
void FilledEllipse::move(int x, int y)
{
	x1 = x1 + x;
	x2 = x2 + x;
	y1 = y1 + y;
	y2 = y2 + y;
}
