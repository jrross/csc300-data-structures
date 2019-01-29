/**************************************************************************//**
 * @file
 *****************************************************************************/

#include <vector>
#include <cmath>
#include "functions.h"
#include "rectangle.h"
#include "ellipse.h"
#include "line.h"
#include "FilledEllipse.h"
#include "FilledRectangle.h"
#define side 40 /*!<this makes the side length of a palette square 40 pixels*/
#define escape 27 /*!<this is used to know when the escape key is being pressed*/

/*********************************************************************//** 
* @author Luke Videckis
*
* @par Description:
* This function will print the palette along with all the shapes drawn
*
* @returns nothing
*
************************************************************************/
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	editShapes(2, nullptr);
	printPalette(0, nullptr);
	glutSwapBuffers();
}

/*********************************************************************//** 
* @author Luke Videckis
*
* @par Description:
* This function will print the palette along with all the shapes drawn
*
* @param[in] key - an unsigned char which is the key that was pressed
* @param[in] x - a float containing the x coordinate
* @param[in] y - a float containing the y coordinate
*
* @returns nothing
*
************************************************************************/
void keyboard(unsigned char key, int x, int y)
{
	if(key == escape || key == 'q')
	{
	    editShapes(1, nullptr);
	    printPalette(2, nullptr);
		glutLeaveMainLoop();
    }
    if(key == 'c') {
        editShapes(1, nullptr);
        display();
    }

    if(key == 'd') {
	editShapes(3, nullptr);
	display();
    }
}

/*********************************************************************//** 
* @author Jeffrey Ross
*
* @par Description:
* This is the function that is called when the window detects an action.
* if the down click is within the area of the palette, it calls another
* function to check what action to take regarding the palette. The function
* then ignores the next release of the mouse. If it is not within the palette,
* it stores the coordinates of the down click in static variables, and then
* makes the corresponding shape using the coordinates from the release.
*
* @param[in] button - an integer containing which action was performed
* @param[in] state - an int containing if the action was pushed or released
* @param[in] x - an int containing the x coordinate
* @param[in] y - an int containing the y coordinate
*
* @returns nothing
*
************************************************************************/
void mouseClick(int button, int state, int x, int y)
{
    const int height = glutGet(GLUT_WINDOW_HEIGHT);
	static int xDown = 100;
	static int yDown = 100;
	static currentProperties curr = { {1.0, 1.0, 1.0}, {1.0, 1.0, 1.0}, 1, 
	                                    false }; //initialize to white rectangle
	static bool plt = false;
	static bool move = false;
	static bool colorSelected = false;
	static bool shapeSelected = false;
	Shape *ptr = nullptr;
	if (state == 0)//down click
	{
		/*if statement to traverse through list of rectangles/pallette with 
		contains function
		if contains return true, check if pallette is true and either change 
		color or move object*/
		if (x < 80 && height - y < 400) //is within the palette
		{
			if( button == 2)
				checkPalette(x, height - y, curr.color);
			if( button == 0)
				checkPalette(x, height - y, curr.border);
			plt = true;
			colorSelected = true;
			return;
		}
		else if (x < 80 && height - y < 520)
		{
			if (x < 40)
			{
				if( height - y < 440 && height - y > 400) // outline rectangle
					curr.shapeType = 4;
				if( height -  y < 480 && height - y > 440) // outline circle
					curr.shapeType = 2;
				
			}
			if (x < 80 && x > 40)
			{
				if(  height - y < 440 && height - y > 400) // filled rectangle
					curr.shapeType = 1;
				if(  height - y < 480 && height -  y > 440) // filled circle
					curr.shapeType = 5;
				if( height -  y < 520 && height -  y > 480) // line
					curr.shapeType = 3;
			}
			shapeSelected = true;
			plt = true;
			return;
		}
		if(editShapes(4, nullptr, x, height - y))
			if(button == 2)
				move = true;
		xDown = x;
		yDown = y;
	}
	else if(state == 1)//up click
	{
		if (move == true)
		{
			y = height - y;
			yDown = height - yDown;
			x = x - xDown;
			y = y - yDown;
			editShapes(5, nullptr, x, y);
			move = false;
			editShapes(6, nullptr, xDown, yDown);
			display();
			return;
		}
		if (plt == true)	//to keep from printing when palette is pressed
		{
			currentProperties *currptr; //update current shape / color indicator
			currptr = &curr;
			if(colorSelected && shapeSelected)
				currptr->ready = true;
			printPalette(1, currptr);
			display();
			plt = false;
			return;
		}
		//if a color and shape have been selected
		if(colorSelected && shapeSelected && button == 0) 
		{
			switch (curr.shapeType)
			{
			case 1://filled rectangle
			    ptr = new FilledRectangle(xDown, height - yDown, x, height - y, 
			                                           curr.color, curr.border);
			    break;
			case 2://ellipse
			    ptr = new Ellipse(xDown, height - yDown, x, height - y, 
			                                                        curr.color);
			    break;
			case 3://line
			    ptr = new Line(xDown, height - yDown,x, height - y, curr.color);
			    break;
			case 4://rectangle
			    ptr = new Rectangle(xDown, height - yDown, x, height - y, 
			                                                  curr.color, true);
			    break;
			case 5://filled ellipse
			    ptr = new FilledEllipse(xDown, height - yDown, x, height - y,
			                                           curr.color, curr.border);
			    break;
			}
   		 	editShapes(0, ptr);
    		display();
		}
	}
}

/*********************************************************************//** 
* @author Luke Videckis
*
* @par Description:
* This function will print the shape in a new location
*
* @param[in] w - an int which is the new width of the shape
* @param[in] h - an int which is the new height of the shape
*
* @returns nothing
*
************************************************************************/
void reshape(int w, int h)
{
    glMatrixMode( GL_PROJECTION );      // use an orthographic projection
    glLoadIdentity();                   // initialize transformation matrix
    gluOrtho2D( 0.0, w, 0.0, h );       // make OpenGL coordinates
    glViewport( 0, 0, w, h );           // the same as the screen coordinates
}

/*********************************************************************//** 
* @author Luke Videckis
*
* @par Description:
* This function will print the shape in a new location
*
* @param[in] width - a const int which is the new width of the shape
* @param[in] height - a const int which is the new height of the shape
*
* @returns nothing
*
************************************************************************/
void reshapeCallbackName(const int width, const int height)
{
    glMatrixMode( GL_PROJECTION );     //use an orthographic projection
    glLoadIdentity();                 //initialize transformation matrix
    gluOrtho2D( 0.0, width, 0.0, height );//make OpenGL coordinates
    glViewport( 0, 0, width, height );//the same as the screen coordinates
}

/*********************************************************************//** 
* @author Jeffrey Ross
*
* @par Description:
* a function that prints out the vector containing the palette and the
* varying shapes above that. It can also be called to update the top left
* portion of the palette.
*
* @param[in] action - an integer to tell what actuion to take
* @param[in] curr - a static struct to tell the current properties of the shape
*
* @returns nothing
*
************************************************************************/
void printPalette(int action, currentProperties *curr)
{
	static vector<Shape*> vect = makePalette();
	static currentProperties topLeft = { {1.0, 1.0, 1.0}, {1.0, 1.0, 1.0}, 1, 
	                                                                    false };
	int i, size = vect.size();
	if (action == 0)
	{
		for (i = 0; i < size; i++)
		{
			vect[i]->draw();
		}
		float Black[3] = {0.0, 0.0, 0.0};
		 // erase previous current shape
		FilledRectangle reset(10, 510, 30, 490, Black, Black);
		reset.draw();
		if(topLeft.ready)
		{
			switch (topLeft.shapeType)
			{
			case 1: {
				FilledRectangle temp(10, 510, 30, 490, topLeft.color, 
				                                                topLeft.border);
				temp.draw();
				}
				break;
			case 2: {
				Ellipse temp(10, 490, 30, 510, topLeft.color);
				temp.draw();
				}
				break;
			case 3: {
				Line temp(10, 490, 30 , 510, topLeft.color);
				temp.draw();
				}
				break;
			case 4: {
				Rectangle temp(10, 510, 30, 490, topLeft.color, true);
				temp.draw();
				}
				break;
			case 5: {
				FilledEllipse temp(10, 490, 30, 510, topLeft.color, 
				                                                topLeft.border);
				temp.draw();
				}
				break;
			}
		}
	}
	if (action == 1)
	{
	    for(int i = 0; i < 3; i++) {
	        topLeft.color[i] = curr->color[i];
	        topLeft.border[i] = curr->border[i];
	    }
		topLeft.ready = curr->ready;
		topLeft.shapeType = curr->shapeType;
	}
	if(action == 2)//called from keyboard to delete memory before exiting
	{
	    int i, size = vect.size();
	    for(i = 0; i < size; i++)
	    {
	        delete vect[i];
	    }
	    vect.clear();
    }
}

/*********************************************************************//** 
* @author Jeffrey Ross
*
* @par Description:
* this function goes through a vector containing all rectangles of the 
* palette, checking to see if they contain the passed x and y values.
* if the rectangle in the palette contains the coordinates, it will change
* the array of current colors or will change the next shape to be drawn.
* (shape portion not yet added)
*
* @param[in] x - coordinate to be checked
* @param[in] y - coordinate to be checked
* @param[in] rtcolor - an array containing RGB values for current color.
*
* @returns - nothing
*
************************************************************************/
void checkPalette(int x, int y, float (&rtcolor)[3])
{
	static vector<Shape*> vect = makePalette();
	int i;
	for ( i = 0; i < 20 ; i++ ) //this checks ONLY colors
	{
		if (vect[i]->contains(x,y))
		{
			rtcolor[0] = vect[i]->color[0];
			rtcolor[1] = vect[i]->color[1];
			rtcolor[2] = vect[i]->color[2];
		}
	}
}
/*********************************************************************//** 
* @author Jeffrey Ross
*
* @par Description:
* this function creates a vector containing rectangles to act as the
* palette. Each rectangle has a different color or shape to represent 
* it's action.
*
*
* @returns vect - a vector of rectangles
*
************************************************************************/
vector<Shape*> makePalette()
{
	static vector<Shape*> vect;
	if(vect.size())
	    return vect;
	float Black[3] = {0.0, 0.0, 0.0};
	Shape *temp2 = new FilledRectangle(0, 0, 80, 520, Black, Black);
	vect.push_back(temp2);
	float color[20][3] = {{0.5, 0.5, 0.5}, {0.6, 0.0, 0.8}, {0.0, 0.0, 1.0},
	                      {0.0, 1.0, 1.0}, {0.0, 1.0, 0.0}, {1.0, 1.0, 0.0},
	                      {1.0, 0.5, 0.0}, {1.0, 0.0, 0.0}, {1.0, 0.0, 1.0},
	                      {1.0, 1.0, 1.0}, {0.25, 0.25, 0.25}, {0.3, 0.0, 0.4},
	                      {0.0, 0.0, 0.5}, {0.0, 0.5, 0.5}, {0.0, 0.5, 0.0},
	                      {0.5, 0.5, 0.0}, {0.5, 0.25, 0.0}, {0.5, 0.0, 0.0},
	                      {0.5, 0.0, 0.5}, {0.7, 0.7, 0.7}};
	float White[3] = {1.0, 1.0, 1.0};
	Shape *temp, *temp1;
	for (int i=0; i<10 ; i++) {
	    temp = new FilledRectangle(0, side*i, side, side+side*i, color[i], 
	                                                                  color[i]);
	    temp1 = new FilledRectangle(side, side*i, 2*side, side+side*i, 
	                                                  color[i+10], color[i+10]);
		vect.push_back(temp);
		vect.push_back(temp1);
	}
	for(int i = 10; i < 13; i++) {
	    temp = new Rectangle(0, side*i, side, side+side*i, White, true);
	    temp1 = new Rectangle(side, side*i, 2*side, side+side*i, White, true);
		vect.push_back(temp);
		vect.push_back(temp1);
	}
   	Shape *line = new Line(50, 490, 70, 510, White);
   	Shape *filCir = new FilledEllipse(50, 450, 70, 470, White, White);
   	Shape *Cir = new Ellipse(10, 450, 30, 470, White);
	Shape *pal = new Rectangle(10, 430, 30, 410, White, true);
	Shape *filpal = new FilledRectangle(50, 430, 70, 410, White, White);
	vect.push_back(line);
	vect.push_back(filCir);
	vect.push_back(Cir);
	vect.push_back(pal);
	vect.push_back(filpal);
	return vect;
}

/*********************************************************************//** 
* @author Jeffrey Ross
*
* @par Description:
* This function maintains all the shapes that are being displayed to 
* the screen. It stores all the shapes in a vector and acts upon them
* accordingly based on the action that is passed in. It can add new shapes,
* print all the shapes, delete one or all shapes, and check if any shapes
* contain an (x,y) coordinate.
*
* @param[in] temp - pointer to a shape to be added
* @param[in] action - represents what action to take
* @param[in] x - x coordinate to be operated on
* @param[in] y - y coordinate to be operated on
*
* @returns true if it contains an (x,y) coordinate
*
************************************************************************/
bool editShapes(int action, Shape *temp, int x, int y)
{
	static vector<Shape*> hold;
	static int j = 0;
	if (action == 0) // called from mouse
		hold.push_back(temp);
	if (action == 1) // called from keyboard
	{
	    int size = hold.size();
	    for(int i = 0; i < size; i++)
	    {
	        delete hold[i];
	    }
		hold.clear();
    	}
	if (action == 2) // called from display
	{
		int size = hold.size();
		for(int i = 0; i < size ; i++)
			hold[i]->draw();
	}
	if (action == 3) //called from keyboard, second case
	{
	    if(hold.size() != 0)
	    {
	        delete hold[hold.size() - 1];
		    hold.pop_back();
	    }
	}
	if (action == 4) //check for contains
	{
	    bool test = false;
		for(unsigned int i = 0; i < hold.size(); i++)
		{
			if(hold[i]->contains(x,y))
			{
				j = i;
				test = true;
			}
		}
		if (test == true)
			return true;
		return false;
	}
	if (action == 5) //moves a shape
	{
	    hold[j]->move(x, y);
	}
	if (action == 6)//brings a shape to the front
	{
		hold.push_back(hold[j]);
		hold.erase(hold.begin()+j);
	}
	return true;
}
