/**************************************************************************//**
 * @file
 *****************************************************************************/

#include "line.h"

/***************************************************************************//** 
* @author Luke Videckis
*
* @par Description:
* This is the constructor for the Line class. It just updates the values for 
* the class. (wow, that's awesome!)
*
* @param[in] x1 - the x value of the down click
* @param[in] y1 - the y value of the down click
* @param[in] x2 - the x value of the up click
* @param[in] y2 - the y value of the up click
* @param[in] color - the float of RGB values for the line 
*
* @returns nothing
*
******************************************************************************/
Line::Line(int x1, int y1, int x2, int y2, float color[3])
{
    this->x1 = x1;
    this->y1 = y1;//height - y1;
    this->x2 = x2;
    this->y2 = y2;//height - y2;
    for(int i = 0; i < 3; i++) {
        this->color[i] = color[i];
    }
}

/***************************************************************************//** 
* @author Luke Videckis
*
* @par Description:
* This is the destructor for the Line class. It does absolutely nothing. Nice.
*
* @returns nothing
*
******************************************************************************/
Line::~Line() {}

/*********************************************************************//**
* @author Luke Videckis
*
* @par Description:
* This function draws a line (oooo spicy)
*
* @returns nothing
*
************************************************************************/
void Line::draw() const
{
   glBegin(GL_LINE_STRIP);
      glColor3fv(this->color);
      glVertex2f(x1, y1);
      glVertex2f(x2, y2);
   glEnd();
}

/*********************************************************************//**
* @author Luke Videckis
*
* @par Description:
* This functions returns true if the click is near the line and false
* otherwise. Near the line means the click is anywhere between 30 pixels above 
* or below the line.
*
* @param[in] a - the x value of the click to be checked
* @param[in] c - the y value of the click to be checked
*
* @returns true if the click is near the line
* @returns false if the click is not near the line
*
************************************************************************/
bool Line::contains(int a, int c) const
{
	float m, b;
	m = (y1 - y2) / (double)(x1 - x2);
	b = y1 - (m * x1);
	//if between x1 and x2
	if ( ((x1 < a) && (a < x2)) || ((x1 > a) && (a > x2)) ) 
	{
	//if between y1 and y2
		if ( ((y1 < c) && (c < y2)) || ((y1 > c) && (c > y2)) ) 
		{
		//y = mx + b give +- leeway
			if (c + 30 >= (m*a + b) && c - 30 <= (m*a + b)) 	
				return true;
		}
	}
	
    return false;
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
void Line::move(int x, int y)
{
	x1 = x1 + x;
	x2 = x2 + x;
	y1 = y1 + y;
	y2 = y2 + y;
}
