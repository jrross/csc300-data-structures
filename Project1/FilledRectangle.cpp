/**************************************************************************//**
 * @file
 *****************************************************************************/

#include "FilledRectangle.h"

/*********************************************************************//* 
* @author Jeffrey Ross
*
* @par Description:
* the constructor for the FilledRectangle class. It just takes all the points
* passed in and puts them into the newly created rectangle.
*
* @param[in] i1 - an int for first x coordinate
* @param[in] j1 - an int for first y coordinate
* @param[in] i2 - an int for second x coordinate
* @param[in] j2 - an int for second y coordinate
* @param[in] c[3] - a float containing RGB values for the color
* @param[in] pal - a bool to tell whether or not the rectangle is in palette
*
* @returns nothing
*
************************************************************************/
FilledRectangle::FilledRectangle(int i1, int j1, int i2, int j2, float c[3], 
                               float b[3]) : Rectangle(i1, j1, i2, j2, c, false)
{
    x1 = i1;
    y1 = j1;
    x2 = i2;
    y2 = j2;
    for(int i = 0; i < 3; i++) {
        this->color[i] = c[i];
	this->border[i] = b[i];
    }
}

/***************************************************************************//** 
* @author Luke Videckis
*
* @par Description:
* This is the destructor for the FilledRectangle class.
*
* @returns nothing
*
******************************************************************************/
FilledRectangle::~FilledRectangle() {}

/*********************************************************************//**
* @author Jeffrey Ross
*
* @par Description:
* a function that prints the filled rectangle to the screen
*
*
* @returns nothing
*
************************************************************************/
void FilledRectangle::draw() const
{
    glBegin(GL_POLYGON);
        glColor3fv(color);
        glVertex2f(this->x1, this->y1);
        glVertex2f(this->x2, this->y1);
        glVertex2f(this->x2, this->y2);
        glVertex2f(this->x1, this->y2);
        glVertex2f(this->x1, this->y1);
    glEnd();

    glBegin(GL_LINE_STRIP);
      	glColor3fv(border);
      	glVertex2f(this->x1, this->y1);
      	glVertex2f(this->x2, this->y1);
      	glVertex2f(this->x2, this->y2);
        glVertex2f(this->x1, this->y2);
        glVertex2f(this->x1, this->y1);
    glEnd();
}

/*********************************************************************//**
* @author Jeffrey Ross
*
* @par Description:
* a function that checks to see if the rectangle contains a certain 
* (x,y) coordinate.
*
*
* @returns true - if it contains the coordinates
* @returns false - if it does not contain the coordinates
*
************************************************************************/
bool FilledRectangle::contains(int a, int b) const
{
    if (((x1 < a) && (a < x2)) || ((x1 > a) && (a > x2))) //if between x1 and x2
	{
		if (((y1 < b)&&(b < y2)) || ((y1 > b)&&(b > y2)))//if between y1 and y2
			return true;
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
void FilledRectangle::move(int x, int y)
{
	x1 = x1 + x;
	x2 = x2 + x;
	y1 = y1 + y;
	y2 = y2 + y;
}
