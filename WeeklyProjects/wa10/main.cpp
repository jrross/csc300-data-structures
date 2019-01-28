/***************************************************************************//**
 * @file main.cpp
 ******************************************************************************/
#include <iostream>
#include <stdlib.h>
#include <GL/glut.h>
#include "util.h"

/// OpenGL callback function prototypes
/// Display handler
void display(void);
/// Handler for keyboard events
void keyboard(const byte key, const int x, const int y);
/// Handler for reshape events
void reshape(const int w, const int h);
// other function prototypes
/// Function to do the initialization of the openGL event handlers
void initOpenGL(const char * filename, const int nrows, const int ncols);

/***************************************************************************//**
@author Paul Hinker
@brief The main function, program entry point

@par Description:
A barebones main to demonstrate the use of OpenGL and it's callback
functionality.
*******************************************************************************/
int main(int argc, char * argv[]) {
	// perform various OpenGL initializations
	glutInit(&argc,argv);
	initOpenGL(argv[1],900,600);

	// go into OpenGL/GLUT main loop, never to return
	glutMainLoop();
}

/***************************************************************************//**
Initialize a variety of glut callback functions

@param[in] windowTitle - The title to place on the window.
@param[in] nrows       - Number of pixels for the window height.
@param[in] ncols       - Number of pixels for the window width.
*******************************************************************************/
void initOpenGL(const char * windowTitle, const int nrows, const int ncols) 
{
        int msec = 1;
	// 32-bit graphics and single buffering
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);

	glutInitWindowSize(nrows,ncols);	// initial window size
	glutInitWindowPosition(50,50);		// initial window  position
	glutCreateWindow(windowTitle);		// window title

	utilityCentral(new InitEvent());

	glClearColor(0,0,0,0);		// use white for glClear command
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	glMatrixMode(GL_PROJECTION);

	// callback routines
	glutDisplayFunc(display);		// how to redisplay window
	glutKeyboardFunc(keyboard);		// how to handle key presses
	glutReshapeFunc(reshape);		// how to resize window
        glutTimerFunc(msec, ticktock, msec);
}
